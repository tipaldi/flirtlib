#include "AbstractFeatureSetMatcher.h"

AbstractFeatureSetMatcher::AbstractFeatureSetMatcher(double acceptanceThreshold):
    m_acceptanceThreshold(acceptanceThreshold)
{

}

OrientedPoint2D AbstractFeatureSetMatcher::generateHypothesis(const std::pair< std::pair<InterestPoint *, InterestPoint *>, std::pair<InterestPoint *, InterestPoint *> > &correspondences) const
{
    Point2D baseDelta = correspondences.first.first->getPosition() - correspondences.second.first->getPosition();
    Point2D transformedDelta = correspondences.first.second->getPosition() - correspondences.second.second->getPosition();
    const Point2D& baseSecond = correspondences.second.first->getPosition();
    const Point2D& transformedSecond = correspondences.second.second->getPosition();
    double denominator = 1. / (baseDelta * baseDelta);
    double cosalpha = denominator * (baseDelta * transformedDelta);
    double sinalpha = - denominator * (baseDelta.ortho() * transformedDelta);
    double x = transformedSecond.x - cosalpha * baseSecond.x + sinalpha * baseSecond.y; 
    double y = transformedSecond.y - cosalpha * baseSecond.y - sinalpha * baseSecond.x;
    return OrientedPoint2D(x, y, atan2(sinalpha, cosalpha));
}

double AbstractFeatureSetMatcher::verifyHypothesis(const std::vector<InterestPoint *> &reference, const std::vector<InterestPoint *> &data, const OrientedPoint2D& transformation,
						   std::vector< std::pair<InterestPoint *, InterestPoint *> > &inlierSet) const
{
//     double maxCorrespondences = reference.size() < data.size() ? reference.size() : data.size();
    double maxCorrespondences = data.size();
    double score = 0.;
    inlierSet.clear();
    inlierSet.reserve(maxCorrespondences);
    for(unsigned int i = 0; i < data.size(); i++){
	double minDistance = 1e17;
	unsigned int minIndex = 0;
	const Point2D point1 = transformation.oplus(data[i]->getPosition());
	for(unsigned int j = 0; j < reference.size(); j++){
	    const Point2D& point2 = reference[j]->getPosition();
	    double currentDistance = (point1 - point2) * (point1 - point2);
	    if(currentDistance < minDistance) {
		minDistance = currentDistance;
		minIndex = j;
	    }
	}
// 	std::cout << "Distance: " << minDistance << ", threshold: " << m_acceptanceThreshold << std::endl;
	if(minDistance < m_acceptanceThreshold){
// 	    std::cout << "\tAdding correspondence" << std::endl;
	    inlierSet.push_back(std::make_pair(data[i], reference[minIndex]));
	} else {
	    minDistance = m_acceptanceThreshold;
	}
	score += minDistance;
    }
    return score;
}
