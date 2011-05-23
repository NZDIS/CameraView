/*
 * Processor.h
 *
 *  Created on: Jun 13, 2010
 *      Author: ethan
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

private:
  cv::StarFeatureDetector stard;
  cv::FastFeatureDetector fastd;
  cv::SurfFeatureDetector surfd;
  std::vector<cv::KeyPoint> keypoints;
  std::vector<std::vector<cv::Point2f> > imagepoints;

  cv::Mat K;
  cv::Mat distortion;
  cv::Size imgsize;

};

#endif /* PROCESSOR_H_ */
