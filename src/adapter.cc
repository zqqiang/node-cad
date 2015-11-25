#include <iostream>
#include "adapter.h"
#include "core.h"

using namespace std;

Adapter::Adapter() {

}

Adapter::~Adapter() {

}

void Adapter::Execute() {
	cout << "Adapter::Execute" << endl;
	Core *core = new Core();
	core->Compute();
}