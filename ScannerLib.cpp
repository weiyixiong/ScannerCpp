#include <iostream>
#include "Scanner.h"
#include "parser.h"
#include "com_htmlparser_jni_Scanner.h"
using namespace std;
using namespace Scannerlib;

JNIEXPORT jobject JNICALL Java_com_htmlparser_jni_Scanner_parseHTMl(JNIEnv *env,
		jobject jthis, jstring data) {

	//ArrayList Object
	jclass cls_ArrayList = env->FindClass("java/util/ArrayList");
	jmethodID construct = env->GetMethodID(cls_ArrayList, "<init>", "()V");
	jobject obj_ArrayList = env->NewObject(cls_ArrayList, construct, "");
	jmethodID arrayList_add = env->GetMethodID(cls_ArrayList, "add",
			"(Ljava/lang/Object;)Z");

	int length = (env)->GetStringLength(data);
	const jchar* jcstr = (env)->GetStringChars(data, 0);
	char* rtn = (char*) malloc(length * 2 + 1);
	WideCharToMultiByte(CP_ACP, 0, (LPCWSTR) jcstr, length, rtn,
			(length * 2 + 1), NULL, NULL);

	//token Object
	jclass cls_token = env->FindClass("com/htmlparser/jni/Token");
	//get field id
	jfieldID token_tag = env->GetFieldID(cls_token, "tag", "I");
	jfieldID token_text = env->GetFieldID(cls_token, "text",
			"Ljava/lang/String;");
	//none argument construct function
	jmethodID construct_token = env->GetMethodID(cls_token, "<init>", "()V");
	//get method id
	Parser *p = new Parser();
	vector<Token*> *res = p->parseHTML(rtn);
	vector<Token*>::iterator iter = res->begin();
	for (; iter != res->end(); iter++) {
		//new a object
		jobject obj_token = env->NewObject(cls_token, construct_token, "");
		if (!(*iter)->_value) {
			continue;
		}
		const char* str = (*iter)->_value;
		jstring rtn = 0;
		int slen = strlen((*iter)->_value);
		unsigned short * buffer = 0;
		if (slen == 0)
			rtn = (env)->NewStringUTF(str);
		else {
			int length = MultiByteToWideChar(CP_ACP, 0, (LPCSTR) str, slen,
			NULL, 0);
			buffer = (unsigned short *) malloc(length * 2 + 1);
			if (MultiByteToWideChar( CP_ACP, 0, (LPCSTR) str, slen,
					(LPWSTR) buffer, length) > 0)
				rtn = (env)->NewString((jchar*) buffer, length);
		}
		if (buffer)
			free(buffer);

		env->SetObjectField(obj_token, token_text, rtn);
		env->SetIntField(obj_token, token_tag, (*iter)->_type);
		env->CallObjectMethod(obj_ArrayList, arrayList_add, obj_token);
		env->DeleteLocalRef(obj_token);

	}

	env->DeleteLocalRef(cls_token);
	env->DeleteLocalRef(cls_ArrayList);
	env->ReleaseStringChars(data, jcstr);
	iter = res->begin();
	while (iter != res->end()) {
		delete *iter;
		++iter;
	}
	res = NULL;
	return obj_ArrayList;
}
