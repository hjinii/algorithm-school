#include <iostream>
#include <fstream>
using namespace std;

void cal() {
	ifstream f_read;
	ofstream f_write;
	f_read.open("bowling.inp");
	f_write.open("bowling.out");

	int T;
	if (f_read.is_open()) {
		f_read >> T; //테스트 개수 (<=10)

		for (int k = 0; k < T; k++) {
			int a;
			double set = 0;
			int count = 21; //입력된 점수 개수
			int arr[21];

			for (int i = 0; i < count; i++) { //배열에 점수 저장
				if (set < 9) { //9set까지
					f_read >> arr[i];
					if (arr[i] == 10 && (set - 0.5 ) != (int)set) { //스트라이크일 때
						count--; //배열 개수 -1
						set++;
					}
					else { //스트라이크 X, 스페어 O (0 10점 포함)
						set += 0.5;
					}
				}
				else { //10set일 때
					f_read >> arr[i];
					f_read >> arr[i + 1];
					if (arr[i] != 10 && (arr[i] + arr[i + 1]) != 10) { //스트라이크 X and 스페어 X -> 10set 기회 2번 
						count--; //배열 개수 -1
						break;
					}
					else { //스트라이크 O or 스페어 O -< 10set 기회 3번
						f_read >> arr[i + 2];
						break;
					}
				}
			}
			

			//점수 계산
			set = 0;
			int result = 0, sum;
			for (int i = 0; i < count; i++) {
				if (arr[i] != 10 && set < 9) { //스트라이크 X
					sum = arr[i] + arr[i + 1];
					if (sum != 10) { //스페어 처리 X
						result += sum;
						i++;
						set++;
					}
					else { //스페어 처리 O
						result += 10;
						result += arr[i + 2]; //다음 점수까지 합산
						i++;
						set++;
					}
				}
				else if (arr[i] == 10 && set < 9) { //스트라이크 O
					result += 10;
					result += arr[i + 1];
					result += arr[i + 2];
					set++;
				}
				else { //마지막 10set 계산
					result += arr[i];
				}
			}
			f_write << result << '\n';
			
		}
	}
	f_read.close();
	f_write.close();
}

int main(void) {
	cal();
}