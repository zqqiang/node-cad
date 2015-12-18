#include <iostream>
#include "adapter.h"
#include "core.h"

using namespace std;

Adapter::Adapter() {

}

Adapter::~Adapter() {

}

void Adapter::Execute(int edge, int faceA, int faceB) {
	cout << " Adapter::Execute edge => " << edge << " faceA => " << faceA << " faceB => " << faceB << endl;
	Core *core = new Core();
	core->Compute();
}