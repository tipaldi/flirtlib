#ifndef CORRESPONDENCERENDERER_H_
#define CORRESPONDENCERENDERER_H_

#include <gui/AbstractRenderer.h>

#include <geometry/point.h>
#include <vector>
#include <utility>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

class CorrespondenceRenderer: public AbstractRenderer {
    public:
	CorrespondenceRenderer(const std::vector< std::pair<Point2D, Point2D> > *correspondences, const std::vector< double > *m_distances = 0);
	
	virtual ~CorrespondenceRenderer() { }
	
/*	CorrespondenceRenderer(const CorrespondenceRenderer& _renderer); 
	
	CorrespondenceRenderer& operator=(const CorrespondenceRenderer& _renderer); 
	
	virtual ~CorrespondenceRenderer();
*/
	inline void setReferenceDepth(float depth)
	    {m_referenceDepth = depth;}
	
	inline void setDataDepth(float depth)
	    {m_dataDepth = depth;}
	
	inline void setColors(const std::vector<Color>& _colors)
	    {m_colors = _colors;}
	inline void setColor(unsigned int _index, float _red, float _green, float _blue, float _alpha = 1.0f)
	    {if(_index < m_colors.size()) m_colors[_index] = Color(_red, _green, _blue, _alpha);}
	
	void setCorrespondences(const std::vector< std::pair<Point2D, Point2D> > *correspondences, const std::vector< double > *m_distances = 0);
	
	inline const std::vector< std::pair<Point2D, Point2D> > * getCorrespondences() const
	    {return m_correspondences;}
	
	inline const std::vector< double > * getDistances() const
	    {return m_distances;}
	
	virtual void render();
	
    protected:
	const std::vector< std::pair<Point2D, Point2D> > *m_correspondences;
	const std::vector< double > *m_distances;
	std::vector<Color> m_colors;
	float m_referenceDepth;
	float m_dataDepth;
	double m_maxDistance;
};

#endif

