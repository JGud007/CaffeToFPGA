#include <string>  

#include "caffe/caffe.hpp"
#include "caffe/layers/memory_data_layer.hpp"

int mnistMain(string inputData){
	int phase = 1;
	shared_ptr<Net<Dtype> > net(new Net<Dtype>(static_cast<Phase>(phase)));
	net->CopyTrainedLayersFrom();
	
	BlobProto *blobProto = new BlobProto();
	blobProto->ParseFromString(inputData);
	net->blob_by_name("data")->FromProto(*blobProto, true);
	net->blob_by_name("data")->Reshape(1, 1, 28, 28);
	
	net->Forward();
	
	int maxIndex = 0;
	float maxProb = 0.0;
	for (int i=0; i<10; i++){
		if(net->blob_by_name("ip2")->data_at(0,i,0,0) > maxProb){
			maxIndex = i;
			maxProb = net->blob_by_name("ip2")->data_at(0,i,0,0);
		}
	}	
	
	return maxIndex;
}