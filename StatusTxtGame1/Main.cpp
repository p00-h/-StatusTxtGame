/*
- HP, MP, 공격력, 방어력을 크기 4의 int형 배열로 선언 및 0으로 초기화합니다.
    
    (배열 이름이 status라면 status[0]은 체력, status[3]은 방어력)
    
- HP와 MP를 입력받고, HP나 MP가 하나라도 50 이하의 숫자를 입력받을 경우 다시 입력받습니다.

- HP와 MP에 값을 입력받은 후 공격력과 방어력을 입력받습니다. 공격력이나 방어력이 하나라도 0 이하의 숫자를 입력받을 경우 다시 입력 받습니다.

- 스탯 관리 시스템을 시작합니다.
     1. HP 회복 2. MP 회복 3. HP 강화 4. MP 강화 5. 공격 스킬 사용 6. 필살기 사용
     선택지를 출력한 후, int형 정수 하나를 입력받아서 해당 선택지를 실행합니다.

- call by pointer를 사용해봅시다. HP, MP포션은 5개씩 기본 지급되며, HP, MP 포션 개수로 5를 저장합니다. 함수는 다음과 같이 정의합니다.
    
    void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
    
- 1, 2번을 선택시 각각 HP/MP가 20 증가하고, 포션의 개수가 1개씩 차감됩니다. 포션이 0개일 경우 사용할 수 없습니다.

- 3, 4번을 선택시 각각 HP/ MP가 2배씩 증가합니다. 이 연산은 두가지 방법이 있으니 잘 생각해보시길 바랍니다.

- 5번 선택시 MP가 50 차감됩니다

- 6번 선택시 MP가 50% 차감됩니다. MP가 0일 경우 사용할 수 없습니다.

- 7번을 선택시 시스템을 종료합니다.
*/

#include <iostream>
using namespace std;

// 포션 개수를 설정하는 함수
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

// HP와 MP를 회복하는 함수
void recoverHP(int* hp, int* hpPotion) {
    if (*hpPotion > 0) {
        *hp += 20;
        (*hpPotion)--;
        cout << "* HP가 20 증가했습니다.\n* 현재 HP: " << *hp << ", 남은 HP 포션: " << *hpPotion << endl;
    }
    else {
        cout << "* HP 포션이 없습니다!" << endl;
    }
}

// MP를 회복하는 함수
void recoverMP(int* mp, int* mpPotion) {
    if (*mpPotion > 0) {
        *mp += 20;
        (*mpPotion)--;
        cout << "* MP가 20 증가했습니다.\n* 현재 MP: " << *mp << ", 남은 MP 포션: " << *mpPotion << endl;
    }
    else {
        cout << "* MP 포션이 없습니다!" << endl;
    }
}
// HP를 강화하는 함수
void enhanceHP(int* hp) {
    *hp *= 2;
    cout << "* HP가 2배 증가했습니다.\n* 현재 HP: " << *hp << endl;
}

// MP를 강화하는 함수
void enhanceMP(int* mp) {
    *mp *= 2;
    cout << "* MP가 2배 증가했습니다.\n* 현재 MP: " << *mp << endl;
}

// 공격 스킬을 사용하는 함수
void useAttackSkill(int* mp) {
    if (*mp >= 50) {
        *mp -= 50;
        cout << "* 공격 스킬을 사용했습니다.\n* 현재 MP: " << *mp << endl;
    }
    else {
        cout << "* MP가 부족합니다!" << endl;
    }
}

// 필살기를 사용하는 함수
void useUltimateSkill(int* mp) {
    if (*mp > 0) {
        *mp = *mp / 2; 
        cout << "* 필살기를 사용했습니다.\n* 스킬 사용으로 MP가 50% 소모되었습니다.\n* 현재 MP: " << *mp << endl;
    }
    else {
        cout << "* MP가 부족합니다!" << endl;
    }
}

int main() {
    int status[4] = {0}; // HP, MP, 공격력, 방어력
    int hpPotion = 0, mpPotion = 0; // 포션 개수

    // HP와 MP 입력
    do {
        cout << "HP와 MP를 입력하세요 (50 이상): ";
        cin >> status[0] >> status[1];
    } while (status[0] < 50 || status[1] < 50);

    // 공격력과 방어력 입력
    do {
        cout << "공격력과 방어력을 입력하세요 (1 이상): ";
        cin >> status[2] >> status[3];
    } while (status[2] <= 0 || status[3] <= 0);

    
	setPotion(5, &hpPotion, &mpPotion); // 기본 포션 지급
	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
	cout << "=============================================" << endl;
   
    // 스탯 관리 시스템 시작
    int choice;
    do {
        cout << "\n<스탯 관리 시스템>" << endl;
        cout << "1. HP 회복" << endl;
        cout << "2. MP 회복" << endl;
        cout << "3. HP 강화" << endl;
        cout << "4. MP 강화" << endl;
        cout << "5. 공격 스킬 사용" << endl;
        cout << "6. 필살기 사용" << endl;
        cout << "7. 종료" << endl;
        cout << "번호를 선택해주세요: ";

		// 사용자 입력
        cin >> choice;
        switch (choice) {
        case 1: recoverHP(&status[0], &hpPotion); break;
        case 2: recoverMP(&status[1], &mpPotion); break;
        case 3: enhanceHP(&status[0]); break;
        case 4: enhanceMP(&status[1]); break;
        case 5: useAttackSkill(&status[1]); break;
        case 6: useUltimateSkill(&status[1]); break;
        case 7: cout << "* 프로그램을 종료합니다." << endl; break;
        default: cout << "* 다시 선택해주세요." << endl; break;
        }
    } while (choice != 7);
    return 0;
}