#include <CL/cl.hpp>
#include <vector>
#include <fstream>

cl::Platform getFirstPlatform() {
  std::vector<cl::Platform> platforms;
  cl::Platform::get(&platforms);
  return platforms.front();
}

cl::Device getFirstDevice(cl::Platform platform) {
  std::vector<cl::Device> devices;
  platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);
  return devices.front();
}

cl::Device getFirstDevice() {
  return getFirstDevice(getFirstPlatform());
}

void addFileToSources(cl::Program::Sources *sources, std::string fileName) {
  std::ifstream kernelcode;
  kernelcode.open(fileName);
  std::string *code = new std::string((std::istreambuf_iterator<char>(kernelcode)), (std::istreambuf_iterator<char>()));
  kernelcode.close();

  sources->push_back({code->c_str(), code->length()});
}

cl::Program::Sources getSourcesFromFile(std::string fileName) {
  // initialize and push code into sources
  cl::Program::Sources sources;
  addFileToSources(&sources, fileName);

  return sources;
}

template <typename T> std::vector<T> initNVector(int n, T val) {
  std::vector<T> vec(n);
  std::fill(vec.begin(), vec.end(), val);
  return vec;
}

template <typename T> T getDeviceInfo(cl::Device device, cl_device_info info) {
  T out;
  device.getInfo(info, &out);
  return out;
}
