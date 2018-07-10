#ifndef CAFFE_UTIL_UPGRADE_PROTO_H_
#define CAFFE_UTIL_UPGRADE_PROTO_H_

#include <string>

#include "caffe/proto/caffe.pb.h"

namespace caffe {

// Read parameters from a file into a NetParameter proto message.
void ReadNetParamsFromTextFileOrDie(const string& param_file,
                                    NetParameter* param);
void ReadNetParamsFromBinaryFileOrDie(const string& param_file,
                                      NetParameter* param);

// Read parameters from a file into a SolverParameter proto message.
void ReadSolverParamsFromTextFileOrDie(const string& param_file,
                                       SolverParameter* param);

}  // namespace caffe

#endif   // CAFFE_UTIL_UPGRADE_PROTO_H_
