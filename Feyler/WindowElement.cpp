#include "WindowElement.h"
#include "Win32GraphicsContext.h"
#include "Bounds.h"
namespace spider {
	WindowElement::WindowElement(GraphicsContext *gc) {
		//    this->mImages = new ImageLibrary();
		VBoxElement::VBoxElement();
		this->gc = gc;

	}

	void WindowElement::pack() {

		bounds bounds = this->gc->getBounds();

		for (vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
			Element *elm = (Element *)static_cast<Node *>(*it);
			elm->setX(0);
			elm->setY(0);
			elm->setWidth(bounds.width);
			elm->setHeight(bounds.height);
			elm->pack();
		}
	}

	void WindowElement::draw() {
		std::vector<Node *> *elements = this->getChildNodes();
		for (std::vector<Node *>::iterator it = elements->begin(); it != elements->end(); ++it) {
			Node *node = (Node *)*it;
			Element *elm = static_cast<Element *>(node);
			if (elm->isVisible())
				elm->draw(0, 0, this->gc);
		}
	}
	void WindowElement::SampleLayout() {
		this->set("bgcolor", "#474747");
		this->setWindowElement(this);
		this->mainWindow = new MainWindowElement(this, new Skin(string("skin.png"), this->createGraphics()));
		this->mainWindow->setWindowElement((WindowElement *)this);
		this->mainWindow->setVisible(true);
		this->mainWindow->layout();
		this->appendChild(mainWindow);
	}
}