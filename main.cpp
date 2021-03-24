#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class SPPlayer {
	private:
		string m_path;
		vector<int> m_freqlist;
	public:
		SPPlayer(string p) {
			m_path = p;
		}
		SPPlayer(const char *p) {
			m_path = std::string(p);
		}
		void operator<<(string p) {
			m_path = p;
			m_freqlist.clear();
		}
		void operator<<(const char *p) {
			m_path = std::string(p);
			m_freqlist.clear();
		}
		void play() {
			fstream f(m_path.c_str(),ios::in);
			if(f.is_open()) {
				while(!f.eof()) {
					int opr = 0;
					int freq = 0;
					int time = 0;
					int arg0 = 0;
					f >> opr;
					if(opr == 1) {              // Play sound : 1 [freq] [time:ms]
						f >> freq >> time;
						Beep(freq,time);
					} else if(opr == 0) {       // Pause : 0 [time:ms]
						f >> time;
						_sleep(time);
//					} else if(opr == 2) {       // Play previous one : 2
//						Beep(freq,time);
					} else if(opr == 3) {       // Add template : 3 [freq]
						f >> arg0;
						m_freqlist.push_back(arg0); 
					} else if(opr == 4) {       // Play template : 4 [template_index] [time:ms]
						f >> arg0 >> time;
						try {
							Beep(m_freqlist[arg0 - 1],time);
						} catch(...) {
							cerr << "Bad Index" << endl;
							return;
						}
					} else if(opr == 5) {       // Comment : 5 [comment...]
						while(1) {
							char c = f.get();
							if(c == '\n') {
								break;
							}
						}
						continue;
					} else {
						cerr << "Bad Operation" << endl;
					}
				}
			} else {
				cerr << "Cannot open file: " << m_path << endl;
			}
		}
};

int main(int argc, char** argv) {
	if(argc == 1) {
		string s;
		cout << "Sound Player (Single MIDI)" << endl;
		cout << "Input path...\nTIPS: The simplest way is drag the file into the console.\n";
		cin >> s;
		SPPlayer player(s);
		player.play();
	} else {
		SPPlayer player(argv[1]);
		player.play();
	}
	return 0;
}
