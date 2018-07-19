#ifndef CAFFE_UTIL_IO_H_
#define CAFFE_UTIL_IO_H_

//#include <boost/filesystem.hpp>
#include <iomanip>
#include <iostream>  // NOLINT(readability/streams)
#include <string>

//#include "google/protobuf/message.h"

#include "caffe/common.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/util/format.hpp"

#ifndef CAFFE_TMP_DIR_RETRIES
#define CAFFE_TMP_DIR_RETRIES 100
#endif

namespace caffe {

using ::google::protobuf::Message;
//using ::boost::filesystem::path;

bool ReadProtoFromTextFile(Message* proto);

bool ReadProtoFromBinaryFile(Message* proto);

}  // namespace caffe

#endif   // CAFFE_UTIL_IO_H_
