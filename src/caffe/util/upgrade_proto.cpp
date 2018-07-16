#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

#include <boost/filesystem.hpp>

#include <map>
#include <string>

#include "caffe/common.hpp"
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
