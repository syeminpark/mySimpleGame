
#include "ModelImporter.h"


	//--------------------------------------------------------------
	void ModelImporter::import(vector<string> modelNames) {
		for (int i = 0; i < modelNames.size(); i++) {
			ofxFBXSource::Scene::Settings settings;//namespace
			settings.filePath = modelNames[i];
			settings.printInfo = true;

			auto fbx = make_shared<ofxFBX>();
			if (fbx->load(settings)) {
				cout << "ofApp :: loaded the scene OK" << endl;
				this->models.insert(make_pair(modelNames[i], fbx));
				cout<<fbx->getFbxFilePath();
			}
			else {
				cout << "ofApp :: Error loading the scene" << endl;
			}
		}
	}

	//--------------------------------------------------------------
	map<string, shared_ptr<ofxFBX>>ModelImporter::getModels() {
		return this->models;
	}

	//--------------------------------------------------------------
	shared_ptr<ofxFBX> ModelImporter::getModel(string name) {

		auto it = this->models.find(name);
		if (it != this->models.end()) {
			cout << "returned: " << name << endl;
			return it->second;
		}
	}

	//--------------------------------------------------------------
