//#include "caffe/common.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/util/io.hpp"
#include "caffe/util/upgrade_proto.hpp"

namespace caffe {

void ReadNetParamsFromTextFileOrDie(NetParameter* param) {
  CHECK(ReadProtoFromTextFile(param))
      << "Failed to parse NetParameter file";
}

void ReadNetParamsFromBinaryFileOrDie(NetParameter* param) {
  CHECK(ReadProtoFromBinaryFile(param))
      << "Failed to parse NetParameter file";
}

// Read parameters from a file into a SolverParameter proto message.
void ReadSolverParamsFromTextFileOrDie(SolverParameter* param) {
  CHECK(ReadProtoFromTextFile(param))
      << "Failed to parse SolverParameter file";
}

}  // namespace caffe
