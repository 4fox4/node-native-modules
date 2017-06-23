#include <node.h>
#include <v8.h>
#include <iostream>

void				Method(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate*	isolate = args.GetIsolate();
	v8::HandleScope	scope(isolate);

	int i = 0;
	unsigned int nb_ops = 0;
	int loop_state = 0;
	while (loop_state < 20)
	{
		while (i < 100000000)
		{
			i++;
			nb_ops++;
		}
		while (i > 0)
		{
			i--;
			nb_ops++;
		}
		loop_state++;
	}
	std::cout << "test c++ std output" << std::endl;
	// args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "coco c++"));
	args.GetReturnValue().Set(v8::Integer::NewFromUnsigned(isolate, nb_ops));
}

void				init(v8::Local<v8::Object> exports)
{
	NODE_SET_METHOD(exports, "test", Method);
}

NODE_MODULE(test, init)
