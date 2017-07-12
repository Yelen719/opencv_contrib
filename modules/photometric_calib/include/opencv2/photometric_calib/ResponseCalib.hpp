// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.

#ifndef _OPENCV_RESPONSECALIB_HPP
#define _OPENCV_RESPONSECALIB_HPP

#include "opencv2/photometric_calib.hpp"
#include "opencv2/photometric_calib/Reader.hpp"

namespace cv { namespace photometric_calib {

class CV_EXPORTS ResponseCalib
{
public:
    ResponseCalib(std::string folderPath, std::string timePath);
    ResponseCalib(std::string folderPath, std::string timePath, int leakPadding, int nIts, int skipFrames);

    void plotE(const double* E, int w, int h, const std::string &saveTo="");

    Vec2d rmse(const double* G, const double* E, const std::vector<double> &exposureVec, const std::vector<unsigned char*> &dataVec, int wh);

    void plotG(const double* G, const std::string &saveTo="");

    void calib();

    inline const std::string& getImageFolderPath () const
    {
        CV_Assert(imageReader);
        return imageReader -> getFolderPath();
    }
    inline const std::string& getTimeFilePath () const
    {
        CV_Assert(imageReader);
        return imageReader -> getTimeFilePath();
    }

private:
    int leakPadding;
    int nIts;
    int skipFrames;
    Reader *imageReader;
};

}}

#endif //_OPENCV_RESPONSECALIB_HPP
