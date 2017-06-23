#include <node.h>
#include <v8.h>

void				Method(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate*	isolate = args.GetIsolate();
	v8::HandleScope	scope(isolate);

	int i = 0;
	int nb_ops = 0;
	int loop_state = 0;
	while (loop_state < 4)
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
	// args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "coco c++"));
	args.GetReturnValue().Set(v8::Int32::New(isolate, nb_ops));
}

void				init(v8::Local<v8::Object> exports)
{
	NODE_SET_METHOD(exports, "test", Method);
}

NODE_MODULE(test, init)