#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
  
int main(int argc, char** argv)
{
    // Read the image file as
    // imread("default.jpg");
    Mat image = imread("/Users/sampathroutu/Desktop/Screenshot 2022-07-19 at 10.30.10 PM",
                       IMREAD_GRAYSCALE);
  
    // Error Handling
    if (image.empty()) {
        cout << "Image File "
             << "Not Found" << endl;
  
        // wait for any key press
        cin.get();
        return -1;
    }
  
    // Show Image inside a window with
    // the name provided
    imshow("Window Name", image);
  
    // Wait for any keystroke
    waitKey(0);
    return 0;
}
