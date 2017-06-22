#include <node.h>
#include <v8.h>

void				Method(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate*	isolate = args.GetIsolate();
	v8::HandleScope	scope(isolate);

	int i = 0;
	while (i < 100000000) {
		i++;
	}
	while (i > 0) {
		i--;
	}

	args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "coco c++"));
}

void				init(v8::Local<v8::Object> exports)
{
	NODE_SET_METHOD(exports, "test", Method);
}

NODE_MODULE(test, init)