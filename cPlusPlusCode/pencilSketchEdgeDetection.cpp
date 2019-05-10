#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){

    //Read input image
    Mat image = imread("../assets/anish.jpg");

    //check if image exists
    if(image.empty()){
        cout<<"can not find image"<<endl;
        return 0;
    }

    //convert to gray scale
    Mat output;
    cvtColor(image, output, COLOR_BGR2GRAY);

    //Apply gaussian blur
    GaussianBlur(output, output, Size(3, 3), 0);

    //Detect edges
    Laplacian(output, output, -1, 5);

    //Invert the binary image
    output = 255 - output;

    //binary thresholding
    threshold(output, output, 150, 255, THRESH_BINARY);

    //create windows to display images
    namedWindow("image", WINDOW_AUTOSIZE);
    namedWindow("pencilsketch", WINDOW_AUTOSIZE);

    //display images
    imshow("image", image);
    imshow("pencilsketch", output);

    //Press esc to exit the program
    waitKey(0);

    //close all the opened windows
    destroyAllWindows();

    return 0;
}