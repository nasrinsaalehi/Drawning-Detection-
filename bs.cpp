////#include<opencv2/opencv.hpp>
////#include<iostream>
////#include<vector>
//// 
////int main()
////{
////    cv::Mat frame;
////    cv::Mat back;
////    cv::Mat fore;
////    cv::VideoCapture cap(0);
////    cv::BackgroundSubtractorMOG2 bg;
////
//// 
////    std::vector<std::vector<cv::Point> > contours;
//// 
////    cv::namedWindow("Frame");
//// 
////    for(;;)
////    {
////        cap >> frame;
////        bg.operator ()(frame,fore);
////        bg.getBackgroundImage(back);
////        cv::erode(fore,fore,cv::Mat());
////        cv::dilate(fore,fore,cv::Mat());
////
////
////
////        cv::imshow("Frame",frame);
////        cv::imshow("foregraound",fore);
////        if(cv::waitKey(30) >= 0) break;
////    }
////    return 0;
////}