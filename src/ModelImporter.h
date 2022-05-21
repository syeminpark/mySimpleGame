#pragma once

#include "ofxFBX.h"
#include "ofMain.h"

class ModelImporter
{
private:
	map<string, shared_ptr<ofxFBX>> models;

public:
	void import(vector<string> modelNames);
	map<string, shared_ptr<ofxFBX>> getModels();
	shared_ptr<ofxFBX> getModel(string name);
};