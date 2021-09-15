#include <opencv/cv.h>  
#include <opencv/highgui.h> 
using namespace cv;

 int main ()  
 {
	VideoCapture cap("M2U01640.mpg");
	Mat img,hsv,binary;
	//grab frame from camera
	cap >> img;
	cvNamedWindow( "Final", CV_WINDOW_NORMAL );
	cvNamedWindow( "first binary", CV_WINDOW_NORMAL );
	cvNamedWindow( "contour", CV_WINDOW_NORMAL );
	while(img.rows>0 && img.cols>0)  { 

		//convert RGB image into HSV image
		cvtColor(img, hsv, CV_BGR2HSV);
	
		//get binary image
		inRange(hsv, Scalar(0, 0, 0), Scalar(12, 255, 255), binary);
	
		//find contours from binary image
		int i;
		vector< vector<Point> > contours;
		findContours(binary, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE); //find contours
		imshow("first binary", binary);
		vector<double> areas(contours.size());
		//find largest contour area
		for(i = 0; i < contours.size(); i++)
		{
			areas[i] = contourArea(Mat(contours[i]));
		}
		//get index of largest contour
		double max;
		Point maxPosition;
		minMaxLoc(Mat(areas),0,&max,0,&maxPosition);
		//draw largest contour.
		drawContours(binary, contours, maxPosition.y, Scalar(255), CV_FILLED);
	
		//draw bounding rectangle around largest contour
		Point center;
		Rect r;

		if (contours.size() >= 1 && max>50 )
		{
			r = boundingRect(contours[maxPosition.y]);
			rectangle(img, r.tl(),r.br(), CV_RGB(255, 0, 0), 3, 8, 0); //draw rectangle
			rectangle(img, cv::Point(0,0), cv::Point(50,35), cv::Scalar(0,255,0), CV_FILLED);
		}
		else
			rectangle(img, cv::Point(0,0), cv::Point(50,35), cv::Scalar(0,0,255), CV_FILLED);

		//get centroid
		center.x = r.x + (r.width/2);
		center.y= r.y + (r.height/2);
		//print x and y co-ordinates on image
		char x[15],y[6];
		itoa(center.x,x,10);
		itoa(center.y,y,10);
		strcat(x,",");
		putText(img, strcat(x,y), cv::Point(600,30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0,0,255), 1, CV_AA);
		imshow("Final",img);
		imshow("contour",binary);

		//grab frame from camera
		cap >> img;

		//wait for key press
		int c = cvWaitKey(10);  
		if((char)c==27 ) break;
	}  
	cvDestroyAllWindows();  
	VideoCapture release;  
	return 0;  
 }  
