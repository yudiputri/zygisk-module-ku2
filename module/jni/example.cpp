#include <android/log.h>
#include <zygisk.hpp>

using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ModuleBase;

class MyModule : public ModuleBase {
public:
    void onLoad(Api *api, JNIEnv *env) override {
        this->api = api;
        this->env = env;
    }

    void preAppSpecialize(AppSpecializeArgs *args) override {
        if (args && args->nice_name) {
            __android_log_print(ANDROID_LOG_INFO, "ZygiskMod", "App: %s", args->nice_name);
        }
    }
private:
    Api *api;
    JNIEnv *env;
};

REGISTER_ZYGISK_MODULE(MyModule);
