#ifndef ABSTRACTRENDERER_H_
#define ABSTRACTRENDERER_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <gui/Color.h>

class AbstractRenderer {
    public:
	virtual void render() = 0;
};

#endif

