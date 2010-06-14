#include "Regression.h"

LineParameters computeNormals(const std::vector<Point2D>& _points, const std::vector<double>& _weights){
    if (_weights.size()!=_points.size()) return computeNormals(_points);
    
    LineParameters result;
    
    double sumWeights = 0;
    for(unsigned int i = 0; i < _weights.size(); i++) sumWeights += _weights[i];
    
    double meanWeightX = 0, meanWeightY = 0;
    for(unsigned int i = 0; i < _weights.size(); i++) {
	meanWeightX += 1.0/(_weights[i]*_weights[i])* _points[i].x;
	meanWeightY += 1.0/(_weights[i]*_weights[i])* _points[i].y;
    }
    meanWeightX = meanWeightX / sumWeights;
    meanWeightY = meanWeightY / sumWeights;
    
    // alpha
    double nominator = 0, denominator = 0;
    for(unsigned int i = 0; i < _weights.size(); i++) {
	nominator += 1.0/(_weights[i]*_weights[i])*(_points[i].x - meanWeightX)*(_points[i].y - meanWeightY);
	denominator += 1.0/(_weights[i]*_weights[i])*((_points[i].y - meanWeightY)*(_points[i].y - meanWeightY) - 
	    (_points[i].x - meanWeightX)*(_points[i].x - meanWeightX));
    }
    
    result.alpha = 0.5 * atan2(-2*nominator,denominator);

    // rho
    result.rho = meanWeightX * cos(result.alpha) + meanWeightY * sin(result.alpha);
    
    // normalize to get the solution facing the robot
    if(result.rho < 0){
	result.alpha += M_PI;
	result.rho = -result.rho;
    }
    
    return result;  
}

LineParameters computeNormals(const std::vector<Point2D>& _points) {
    return computeNormals(_points, std::vector<double>(_points.size(),1.0));
}
