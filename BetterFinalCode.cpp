//#include <iostream>
//#include <opencv/ml.h>
//#include <conio.h>
//#include <opencv/cv.h>  
//#include <opencv/highgui.h> 
//using namespace cv;
//
// void main (void)  
// {
//	VideoCapture record("M2U01640.mpg");
//	Mat mainImg,hsvImg,binaryImg;
//	cvNamedWindow( "MainWindow", 1 );
//	record >> mainImg; //start video capturing
//	while(mainImg.rows>0 && mainImg.cols>0)  { 	
//		
//		cvtColor(mainImg, hsvImg, CV_BGR2HSV); //RGB to HSV conversion
//		inRange(hsvImg, Scalar(0, 0, 0), Scalar(12, 255, 255), binaryImg); //binary image
//	
//		//contour detection in binary image
//		vector< vector<Point> > vect_of_contours; int i;
//		findContours(binaryImg, vect_of_contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
//		vector<double> inBox(vect_of_contours.size());
//
//		// select biggest contour and it's index
//		for(i = 0; i < vect_of_contours.size(); i++)
//			inBox[i] = contourArea(Mat(vect_of_contours[i]));
//		double max; Point maxIndx;	
//		minMaxLoc(Mat(inBox),0,&max,0,&maxIndx);
//	
//		//draw bounding rectangle around largest contour
//		Point center; Rect bb;
//
//		if ( max>48 && vect_of_contours.size() >= 1)
//		{
//			bb = boundingRect(vect_of_contours[maxIndx.y]);
//			rectangle(mainImg, bb.tl(),bb.br(), CV_RGB(0, 255, 255), 3, 8, 0); //draw rectangle
//			circle(mainImg, cv::Point(680,30), 25, cv::Scalar(0,255,0), CV_FILLED);
//		}
//		else
//			circle(mainImg, cv::Point(680,30), 25, cv::Scalar(0,0,255), CV_FILLED);
//
//		//calculate center of detected object
//		center.x = bb.width/2+ bb.x ;
//		center.y= bb.height/2+ bb.y ;
//
//		char x[6],y[6];
//		itoa(center.x,x,10);
//		itoa(center.y,y,10);
//		strcat(x," ,");
//		strcat(x,y);
//		rectangle(mainImg, cv::Point(20,10), cv::Point(120,45), cv::Scalar(0,0,0), CV_FILLED);
//		putText(mainImg, x, cv::Point(30,30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(255,255,255), 2, CV_AA);
//		imshow("MainWindow",mainImg);
//		record >> mainImg; //continue video capturing
//		int c = cvWaitKey(10);if((char)c==27 ) break;
//	}  	  
//	VideoCapture release; 
//	cvDestroyAllWindows(); 
// }  
