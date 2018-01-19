#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <thread>
#include <atomic>
#include <chrono>

using namespace cv;
using namespace std;

atomic<bool> is_running;
VideoCapture cap;
Mat src;

void capture(){
  while(is_running){
    cap >> src;
  }
}

int main(int argc, char** argv)
{
  //Opencv
  int loop_control;
  is_running = true;

  const int CAMERA = 0;
  const int WIDTH = 1920;
  const int HEIGHT = 1080;

  //Tries to open camera
  if(!cap.open(CAMERA))
    return 0;


  //Set Camera Vars
  cap.set(CV_CAP_PROP_FRAME_WIDTH, WIDTH);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);

  //Loop while waiting for VideoCapture
  while(src.empty());


  while(is_running)
  {


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
