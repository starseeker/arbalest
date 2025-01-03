//
// Created by Sadeep on 11-Jun.
//

#ifndef RT3_DOCUMENT_H
#define RT3_DOCUMENT_H

#include "ADisplay.h"
#include "ObjectTree.h"
#include "ObjectTreeWidget.h"
#include "Properties.h"
#include "GeometryRenderer.h"
#include "ADisplayGrid.h"
#include <include/RaytraceView.h>

class Properties;
class ADisplay;
class GeometryRenderer;
class ADisplayGrid;
class RaytraceView;
class ObjectTreeWidget;

class Document {
private:
    QString *filePath = nullptr;
    BRLCAD::MemoryDatabase *database;
    ADisplayGrid *displayGrid;
    ObjectTreeWidget *objectTreeWidget;
    Properties *properties;
    const int documentId;
    ObjectTree* objectTree;
    GeometryRenderer * geometryRenderer;
    bool modified;


public:
    explicit Document(int documentId, const QString *filePath = nullptr);
    virtual ~Document();

    void modifyObject(BRLCAD::Object* newObject);

    RaytraceView * raytraceWidget;
    // getters setters
    QString* getFilePath() const
    {
	    return filePath;
    }

    RaytraceView * getRaytraceWidget() const
    {
        return raytraceWidget;
    }
    BRLCAD::ConstDatabase* getDatabase() const
    {
        return database;
    }

    ADisplay* getADisplay();

    ObjectTreeWidget* getObjectTreeWidget() const
    {
	    return objectTreeWidget;
    }

    Properties* getProperties() const
    {
	    return properties;
    }

    ADisplayGrid *getADisplayGrid()  {
        return displayGrid;
    }

    int getDocumentId() const
    {
	    return documentId;
    }

    ObjectTree* getObjectTree() const
    {
	    return objectTree;
    }
    GeometryRenderer *getGeometryRenderer(){
        return geometryRenderer;
    }

    void setFilePath(const QString& filePath)
    {
        this->filePath = new QString(filePath);
    }

    bool isModified();
    bool Add(const BRLCAD::Object& object);
    bool Save(const char* fileName);
    void getBRLCADConstObject(const QString& objectName, const std::function<void(const BRLCAD::Object&)>& func) const;
    void getBRLCADObject(const QString& objectName, const std::function<void(BRLCAD::Object&)>& func);
};


#endif //RT3_DOCUMENT_H
