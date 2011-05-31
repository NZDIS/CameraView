/*
 * Processor.h
 *
 *  Created on: Jun 13, 2010
 *      Author: ethan
 *
 *  Modified:
 *      Author: Mariusz Nowostawski
 *
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include <vector>

#include "image_pool.h"

// Adding support for logging
#include <android/log.h> 

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, "NZDIS CameraView", __VA_ARGS__) 
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , "NZDIS CameraView", __VA_ARGS__) 
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , "NZDIS CameraView", __VA_ARGS__) 
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , "NZDIS CameraView", __VA_ARGS__) 
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , "NZDIS CameraView", __VA_ARGS__) 

// FD constants
#define DETECT_FAST 0
#define DETECT_STAR 1
#define DETECT_SURF 2


class Processor
{
public:

  Processor();
  virtual ~Processor();

  void detectAndDrawFeatures(int idx, image_pool* pool, int feature_type);
	
  bool detectAndDrawFace(int idx, image_pool* pool);
  bool detectAndDrawChessboard(int idx, image_pool* pool);

  void resetChess();

  int getNumberDetectedChessboards();

  void calibrate(const char* filename);

  void drawText(int idx, image_pool* pool, const char* text);
  void drawRate(int idx, image_pool* pool, const float rate);
	
private:
  cv::StarFeatureDetector stard;
  cv::FastFeatureDetector fastd;
  cv::SurfFeatureDetector surfd;
  std::vector<cv::KeyPoint> keypoints;
  std::vector<std::vector<cv::Point2f> > imagepoints;

  cv::Mat K;
  cv::Mat distortion;
  cv::Size imgsize;

  // Create memory for calculations
  CvMemStorage* storage;
	
  // Create a new Haar classifier
  CvHaarClassifierCascade* cascade;
	
  // String that contains the cascade name
  char* cascade_name;	
	
};

#endif /* PROCESSOR_H_ */
