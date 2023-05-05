
#include <iostream>
#include <sstream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ximgproc.hpp>
#include <opencv2/ximgproc/segmentation.hpp>

static void displayImage(std::string const & windowName, cv::Mat image)
{
    cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
    cv::imshow(windowName, image);
    cv::waitKey(0);
}

int main(int argc, const char * argv[])
{
    // Load the image in grayscale mode
    cv::Mat input = cv::imread(argv[1], cv::ImreadModes::IMREAD_GRAYSCALE);
    displayImage("Image", input);
    
    auto sgm = cv::ximgproc::segmentation::createGraphSegmentation();

    cv::Mat out;
    sgm->processImage(input, out);
    if(!out.data)
        return 1;

    out.convertTo(out, CV_32F);
    displayImage("Image", out);
    return 0;
}
