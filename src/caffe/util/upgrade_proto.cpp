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

void ReadNetParamsFromTextFileOrDie(const string& param_file,
                                    NetParameter* param) {
  CHECK(ReadProtoFromTextFile(param_file, param))
      << "Failed to parse NetParameter file: " << param_file;
}

void ReadNetParamsFromBinaryFileOrDie(const string& param_file,
                                      NetParameter* param) {
  CHECK(ReadProtoFromBinaryFile(param_file, param))
      << "Failed to parse NetParameter file: " << param_file;
}

// Read parameters from a file into a SolverParameter proto message.
void ReadSolverParamsFromTextFileOrDie(const string& param_file,
                                       SolverParameter* param) {
  CHECK(ReadProtoFromTextFile(param_file, param))
      << "Failed to parse SolverParameter file: " << param_file;
}

}  // namespace caffe
