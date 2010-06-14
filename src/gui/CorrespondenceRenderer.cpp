#include "CorrespondenceRenderer.h"

CorrespondenceRenderer::CorrespondenceRenderer(const std::vector< std::pair<Point2D, Point2D> > *correspondences, const std::vector< double > *distances):
    m_correspondences(correspondences),
    m_distances(NULL),
    m_referenceDepth(0),
    m_dataDepth(0),
    m_maxDistance(0)
{
    if(m_correspondences){
	m_colors.resize(m_correspondences->size(),Color(1.f,0.f,0.f,1.f));
	if(distances && m_correspondences->size() == distances->size()){
	    m_distances = distances;
	    for(unsigned int i = 0; i < m_distances->size(); i++){
		m_maxDistance = m_maxDistance > (*m_distances)[i] ? m_maxDistance : (*m_distances)[i];
	    }
	}
    }
}

void CorrespondenceRenderer::setCorrespondences(const std::vector< std::pair<Point2D, Point2D> > *correspondences, const std::vector< double > *distances)
{
    m_correspondences = correspondences;
    m_distances = distances;
    if(m_correspondences){
	m_colors.resize(m_correspondences->size(),Color(1.f,0.f,0.f,1.f));
	if(distances && m_correspondences->size() == distances->size()){
	    m_distances = distances;
	    for(unsigned int i = 0; i < m_distances->size(); i++){
		m_maxDistance = m_maxDistance > (*m_distances)[i] ? m_maxDistance : (*m_distances)[i];
	    }
	}
    }
}

void CorrespondenceRenderer::render()
{
    if(!m_correspondences) return;
    glPushMatrix();
    float width;
    glGetFloatv(GL_LINE_WIDTH, &width);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    for(unsigned int i = 0; i < m_correspondences->size(); i++){
	float alpha = m_distances ? 1.f - (*m_distances)[i]/m_maxDistance : 1.f;
// 	glColor4f(m_colors[i].red(), m_colors[i].green(), m_colors[i].blue(), alpha);
	glColor4f(alpha, alpha, alpha, 1.f);
	glVertex3f((*m_correspondences)[i].first.x, (*m_correspondences)[i].first.y, m_referenceDepth);
	glVertex3f((*m_correspondences)[i].second.x, (*m_correspondences)[i].second.y, m_dataDepth);
    }
    glEnd();
    glLineWidth(width);
    glPopMatrix();
}