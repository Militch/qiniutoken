#include <iostream>
#include <gflags/gflags.h>
#include <ctime>

#include <algorithm>
#include <string>

#include <qiniu/rs.h>

using namespace std;


static bool ValidateRequired(const char* flag_name, const std::string& value){
    return !value.empty();
}


DEFINE_bool(upload, false, "upload option");
DEFINE_string(ak, "", "Access Key");
DEFINE_string(sk, "", "Secret Key");
DEFINE_string(scope, "", "scope");

DEFINE_validator(ak, &ValidateRequired);
DEFINE_validator(sk, &ValidateRequired);
DEFINE_validator(scope, &ValidateRequired);


char* CreateUploadToken(){
    Qiniu_Mac mac;
    mac.accessKey = FLAGS_ak.c_str();
    mac.secretKey = FLAGS_sk.c_str();
    Qiniu_RS_PutPolicy putPolicy;
    Qiniu_Zero(putPolicy);
    putPolicy.scope = FLAGS_scope.c_str();
    char* uptoken;
    uptoken = Qiniu_RS_PutPolicy_Token(&putPolicy, &mac);
//    Qiniu_Free(uptoken);
    return uptoken;
}
bool HandleUploadAction(){
    char* upload_token = CreateUploadToken();
    cout << upload_token << endl;
    return true;
}


int main(int argc, char **argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    Qiniu_Global_Init(-1);
    if (FLAGS_upload){
        HandleUploadAction();
    }
    return 0;
}