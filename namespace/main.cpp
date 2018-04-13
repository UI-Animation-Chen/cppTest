namespace jni {
	int j;
}

namespace czf {
	int age;
  namespace hobby {
		int num;
    namespace code {
			int level;
}}}

namespace czf {
	int getNum() {
		int j = jni::j;
		int level = hobby::code::level;
		return czf::hobby::num;
	}
  namespace hobby{
		int getHobby() {
			int level = code::level;
			return num;
		}
}}

namespace UI {
	class Text {
	public:
		char *text;
	};
}

class Text {
public:
	int length;
};

int main(int argc, char *argv[]) {
	int num = czf::getNum();
	char c = 'a';
	UI::Text t;
	t.text = &c;
	return 0;
}







