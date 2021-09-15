//#include <opencv/cv.h>  
//#include <opencv/highgui.h> 
//using namespace cv;
//
// int main ()  
// {  
//	cvNamedWindow( "Final", 1 );
//	Mat img,hsv,hsv2,binary,binary2;
//  
//	VideoCapture cap(0);  
//	while(true)  
//	{ 
//		//grab frame from camera
//		cap >> img;
//
//		//convert RGB image into HSV image
//		cvtColor(img, hsv, CV_BGR2HSV);
//	
//		//get binary image
//		inRange(hsv, Scalar(0, 81, 95), Scalar(31, 255, 255), binary);
//	
//		//find contours from binary image
//		int i;
//		vector< vector<Point> > contours;
//		vector< vector<Point> > fcontours;
//		findContours(binary, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE); //find contours
//		imshow("first binary", binary);
//		
//		vector<double> areas(contours.size());
//		//find largest contour area
//		for(i = 0; i < contours.size(); i++)
//		{
//			areas[i] = contourArea(Mat(contours[i]));
//		}
//		//get index of largest contour
//		double max;
//		Point maxPosition;
//		minMaxLoc(Mat(areas),0,&max,0,&maxPosition);
//		//draw largest contour.
//		drawContours(binary, contours, maxPosition.y, Scalar(255), CV_FILLED);
//	
//		//draw bounding rectangle around largest contour
//		Point center;
//		Rect r,r2;
//
//		if (contours.size() >= 1 && max>50 )
//		{
//			r = boundingRect(contours[maxPosition.y]);
//			rectangle(img, r.tl(),r.br(), CV_RGB(255, 0, 0), 3, 8, 0); //draw rectangle
//			rectangle(img, cv::Point(0,0), cv::Point(50,35), cv::Scalar(0,255,0), CV_FILLED);
//
//			//get face rectangle**************************
//			binary2= binary(r);
//			imshow("face22", binary2);
//			//cv::Mat face= img(r);
//			//cvtColor(face, hsv2, CV_BGR2HSV); 
//
//			//inRange(hsv2, Scalar(0, 0, 0), Scalar(255, 255, 30), binary2); //find black areas
//			vector<Vec3f> circles;
//			GaussianBlur( binary2, binary2, Size(9, 9), 2, 2 );
//			HoughCircles( binary2, circles, CV_HOUGH_GRADIENT, 1, binary2.rows/8, 100, 24, 0, 40 );
//			imshow ("image face", binary2);
//			cv::imwrite("face1.jpg", binary2);
//			findContours(binary2, fcontours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE); //find contours
//			//get centroid
//			center.x = r.x + (r.width/2);
//			center.y= r.y + (r.height/2);
//
//			for(int i=0; i< circles.size(); i++)
//			{
//				Point c(cvRound(circles[i][0]), cvRound(circles[i][1]));
//				int radius = cvRound(circles[i][2]);
//				circle( img, c+r.tl(), radius, Scalar(255,0,0), 2, 8, 0 );
//			}
//			//*********************************************************************************
//		}
//		else
//			rectangle(img, cv::Point(0,0), cv::Point(50,35), cv::Scalar(0,0,255), CV_FILLED);
//
//		
//		
//		//print x and y co-ordinates on image
//		char x[15],y[6];
//		itoa(center.x,x,10);
//		itoa(center.y,y,10);
//		strcat(x,",");
//		putText(img, strcat(x,y), cv::Point(600,30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0,0,255), 1, CV_AA);
//		imshow("Final",img);
//		imshow("contour",binary);
//		//wait for key press
//		int c = cvWaitKey(10);  
//		if((char)c==27 ) break;
//	}  
//	cvDestroyAllWindows();  
//	VideoCapture release;  
//	return 0;  
// }  
