/*
- HP, MP, ���ݷ�, ������ ũ�� 4�� int�� �迭�� ���� �� 0���� �ʱ�ȭ�մϴ�.
    
    (�迭 �̸��� status��� status[0]�� ü��, status[3]�� ����)
    
- HP�� MP�� �Է¹ް�, HP�� MP�� �ϳ��� 50 ������ ���ڸ� �Է¹��� ��� �ٽ� �Է¹޽��ϴ�.

- HP�� MP�� ���� �Է¹��� �� ���ݷ°� ������ �Է¹޽��ϴ�. ���ݷ��̳� ������ �ϳ��� 0 ������ ���ڸ� �Է¹��� ��� �ٽ� �Է� �޽��ϴ�.

- ���� ���� �ý����� �����մϴ�.
     1. HP ȸ�� 2. MP ȸ�� 3. HP ��ȭ 4. MP ��ȭ 5. ���� ��ų ��� 6. �ʻ�� ���
     �������� ����� ��, int�� ���� �ϳ��� �Է¹޾Ƽ� �ش� �������� �����մϴ�.

- call by pointer�� ����غ��ô�. HP, MP������ 5���� �⺻ ���޵Ǹ�, HP, MP ���� ������ 5�� �����մϴ�. �Լ��� ������ ���� �����մϴ�.
    
    void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
    
- 1, 2���� ���ý� ���� HP/MP�� 20 �����ϰ�, ������ ������ 1���� �����˴ϴ�. ������ 0���� ��� ����� �� �����ϴ�.

- 3, 4���� ���ý� ���� HP/ MP�� 2�辿 �����մϴ�. �� ������ �ΰ��� ����� ������ �� �����غ��ñ� �ٶ��ϴ�.

- 5�� ���ý� MP�� 50 �����˴ϴ�

- 6�� ���ý� MP�� 50% �����˴ϴ�. MP�� 0�� ��� ����� �� �����ϴ�.

- 7���� ���ý� �ý����� �����մϴ�.
*/

#include <iostream>
using namespace std;

// ���� ������ �����ϴ� �Լ�
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

// HP�� MP�� ȸ���ϴ� �Լ�
void recoverHP(int* hp, int* hpPotion) {
    if (*hpPotion > 0) {
        *hp += 20;
        (*hpPotion)--;
        cout << "* HP�� 20 �����߽��ϴ�.\n* ���� HP: " << *hp << ", ���� HP ����: " << *hpPotion << endl;
    }
    else {
        cout << "* HP ������ �����ϴ�!" << endl;
    }
}

// MP�� ȸ���ϴ� �Լ�
void recoverMP(int* mp, int* mpPotion) {
    if (*mpPotion > 0) {
        *mp += 20;
        (*mpPotion)--;
        cout << "* MP�� 20 �����߽��ϴ�.\n* ���� MP: " << *mp << ", ���� MP ����: " << *mpPotion << endl;
    }
    else {
        cout << "* MP ������ �����ϴ�!" << endl;
    }
}
// HP�� ��ȭ�ϴ� �Լ�
void enhanceHP(int* hp) {
    *hp *= 2;
    cout << "* HP�� 2�� �����߽��ϴ�.\n* ���� HP: " << *hp << endl;
}

// MP�� ��ȭ�ϴ� �Լ�
void enhanceMP(int* mp) {
    *mp *= 2;
    cout << "* MP�� 2�� �����߽��ϴ�.\n* ���� MP: " << *mp << endl;
}

// ���� ��ų�� ����ϴ� �Լ�
void useAttackSkill(int* mp) {
    if (*mp >= 50) {
        *mp -= 50;
        cout << "* ���� ��ų�� ����߽��ϴ�.\n* ���� MP: " << *mp << endl;
    }
    else {
        cout << "* MP�� �����մϴ�!" << endl;
    }
}

// �ʻ�⸦ ����ϴ� �Լ�
void useUltimateSkill(int* mp) {
    if (*mp > 0) {
        *mp = *mp / 2; 
        cout << "* �ʻ�⸦ ����߽��ϴ�.\n* ��ų ������� MP�� 50% �Ҹ�Ǿ����ϴ�.\n* ���� MP: " << *mp << endl;
    }
    else {
        cout << "* MP�� �����մϴ�!" << endl;
    }
}

int main() {
    int status[4] = {0}; // HP, MP, ���ݷ�, ����
    int hpPotion = 0, mpPotion = 0; // ���� ����

    // HP�� MP �Է�
    do {
        cout << "HP�� MP�� �Է��ϼ��� (50 �̻�): ";
        cin >> status[0] >> status[1];
    } while (status[0] < 50 || status[1] < 50);

    // ���ݷ°� ���� �Է�
    do {
        cout << "���ݷ°� ������ �Է��ϼ��� (1 �̻�): ";
        cin >> status[2] >> status[3];
    } while (status[2] <= 0 || status[3] <= 0);

    
	setPotion(5, &hpPotion, &mpPotion); // �⺻ ���� ����
	cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� 5��)" << endl;
	cout << "=============================================" << endl;
   
    // ���� ���� �ý��� ����
    int choice;
    do {
        cout << "\n<���� ���� �ý���>" << endl;
        cout << "1. HP ȸ��" << endl;
        cout << "2. MP ȸ��" << endl;
        cout << "3. HP ��ȭ" << endl;
        cout << "4. MP ��ȭ" << endl;
        cout << "5. ���� ��ų ���" << endl;
        cout << "6. �ʻ�� ���" << endl;
        cout << "7. ����" << endl;
        cout << "��ȣ�� �������ּ���: ";

		// ����� �Է�
        cin >> choice;
        switch (choice) {
        case 1: recoverHP(&status[0], &hpPotion); break;
        case 2: recoverMP(&status[1], &mpPotion); break;
        case 3: enhanceHP(&status[0]); break;
        case 4: enhanceMP(&status[1]); break;
        case 5: useAttackSkill(&status[1]); break;
        case 6: useUltimateSkill(&status[1]); break;
        case 7: cout << "* ���α׷��� �����մϴ�." << endl; break;
        default: cout << "* �ٽ� �������ּ���." << endl; break;
        }
    } while (choice != 7);
    return 0;
}