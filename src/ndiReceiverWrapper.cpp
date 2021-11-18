#include "ndiReceiverWrapper.h"



NdiReceiver::NdiReceiver()
{
    
}

int NdiReceiver::initialize()
{
    // Create a finder
	NDIlib_find_instance_t pNDI_find = NDIlib_find_create_v2();
	if (!pNDI_find) return 0;

	// Wait until there is one source
	uint32_t no_sources = 0;
	const NDIlib_source_t* p_sources = NULL;
	while (!no_sources)
	{	// Wait until the sources on the nwtork have changed
		printf("Looking for sources ...\n");
		NDIlib_find_wait_for_sources(pNDI_find, 1000/* One second */);
		p_sources = NDIlib_find_get_current_sources(pNDI_find, &no_sources);
	}

    NDIlib_recv_create_v3_t recv_desc;
    recv_desc.color_format = NDIlib_recv_color_format_BGRX_BGRA;

	// We now have at least one source, so we create a receiver to look at it.
	pNDI_recv = NDIlib_recv_create_v3(&recv_desc);

	if (!pNDI_recv) return 0;

	// Connect to our sources
	NDIlib_recv_connect(pNDI_recv, p_sources + 0);

	// Destroy the NDI finder. We needed to have access to the pointers to p_sources[0]
	NDIlib_find_destroy(pNDI_find);	
    return 0;
}

int NdiReceiver::captureInLoop()
{
    NDIlib_video_frame_v2_t video_frame;
    
    // openCV matrix, might be slow  
    cv::Mat mat1 = cv::Mat::zeros(frameHigh, frameWidth, CV_8UC4);
    
    cv::Mat ledMat = cv::Mat::zeros(16, 16, CV_8UC4);

    while(cv::waitKey(1) != 27)
    {// The descriptors
		switch (NDIlib_recv_capture_v2(pNDI_recv, &video_frame, nullptr, nullptr, 5000))
		{	
			// Video data
			case NDIlib_frame_type_video:
                memcpy(mat1.data, video_frame.p_data , frameWidth * frameHigh * pixelSize);

                //resize(mat1, ledMat, cv::Size(500, 500), cv::INTER_LINEAR);

                cv::imshow("Display window", mat1);
				NDIlib_recv_free_video_v2(pNDI_recv, &video_frame);
                break;

		}
	} 
}


int NdiReceiver::cleanup()
{
    // Destroy the receiver
	NDIlib_recv_destroy(pNDI_recv);

	// Not required, but nice
	NDIlib_destroy();
}