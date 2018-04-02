#ifndef H_SPIDER_WINDOW_ELEMENT
#define H_SPIDER_WINDOW_ELEMENT
#include "VBoxElement.h"
#include "ImageLibrary.h"
#include "GraphicsContext.h"
namespace spider {

	class WindowElement : public VBoxElement {
protected:
	GraphicsContext * gc;
//        ImageLibrary *mImages;
public:
  /*      ImageLibrary *images() {
            return this->mImages;
        }*/
		void draw();
		void pack();
		WindowElement(GraphicsContext *gc);
		virtual void invalidateRegion(rectangle rect) {}
        virtual string getType() {
            return "window";
        }
        virtual void scrollTo(int x, int y) {}
        virtual void scroll(int x, int y) {}
		void SampleLayout();

	};

};

#endif
