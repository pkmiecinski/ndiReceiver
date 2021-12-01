#include <iostream>

#include <Processing.NDI.Lib.h>
#include <opencv2/opencv.hpp>

class NdiReceiver 
{
    public:
        NdiReceiver();
        int initialize();
        int cleanup();
        void captureInLoop(std::string agrument);
        int startNdiRecvThread();
        int stopNdiRecvThread();
        int setOutputSize(uint16_t outputWidthArg, uint16_t outputHeightArg);
        uint8_t getOutputPixelValueRed(uint16_t outputWidthArg, uint16_t outputHeightArg);
        uint8_t getOutputPixelValueGreen(uint16_t outputWidthArg, uint16_t outputHeightArg);
        uint8_t getOutputPixelValueBlue(uint16_t outputWidthArg, uint16_t outputHeightArg);

    private:

    NDIlib_recv_instance_t pNDI_recv;
    const std::uint16_t  frameWidth = 1920;
    const std::uint16_t  frameHigh  = 1080;
    const std::uint8_t   pixelSize = 4;

    uint16_t outputWidth;
    uint16_t outputHeight;

    const std::string threadName = "NDI Video Capture Thread";

    cv::Mat mat1; 
    cv::Mat outputMatrix;

};

