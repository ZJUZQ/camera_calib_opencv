#include "opencv2/opencv.hpp"
#include <sstream>

using namespace cv;
using namespace std;

int main(int, char**)
{
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("frame",1);
    int count = 0;

    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        //cvtColor(frame, edges, COLOR_BGR2GRAY);
        //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        //Canny(edges, edges, 0, 30, 3);
        imshow("frame", frame);
        char c = cv::waitKey(2);
        stringstream f;
        f << "images/image_" << count << ".png";
        if(c == 's'){
            cv::imwrite(f.str(), frame);
            count++;
        }

        if(c == 'q')
            break;
        
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}