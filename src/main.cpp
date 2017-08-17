#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <thread>
#include <atomic>
#include <chrono>
#include <curl/curl.h>

using namespace cv;

int main(int argc, char** argv)
{
  //Opencv
  Mat src;
  int loop_control;
  bool is_running = true;
  VideoCapture cap;
  const int CAMERA = 1;
  const int WIDTH = 1920;
  const int HEIGHT = 1080;

  //Tries to open camera
  if(!cap.open(CAMERA))
    return 0;

  //Set Camera Vars
  cap.set(CV_CAP_PROP_FRAME_WIDTH, WIDTH);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);

  while(is_running)
  {

    //Initial Image
    cap >> src;
    //Processing




    //End Processing
    imshow("src",src);

    //Loop logic
    loop_control = waitKey(1);
    if(loop_control == 27)
      is_running = false;
    else if(loop_control == 32)
      std::cout << "Space Pressed\n";

  }

  cap.release();
  return 0;

}
