#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;
#define endl '\n'

using ll = long long;
using ull = unsigned long long;

const ll modd = 1e9 + 7;
const ll inf = 1e9;
const int N = 1e6 + 7;

struct SV
{
    std::string mssv, name, sx, dis;
    float dtb;
};
struct Node
{
    SV data;
    Node* next;
};
Node* head = nullptr;
int n;

void sosanh_mssv(Node*& head)
{
    std::vector<SV> svVector;
    Node* current = head;
    while (current != nullptr)
    {
        svVector.push_back(current->data);
        current = current->next;
    }
    std::sort(svVector.begin(), svVector.end(), [](const SV& a, const SV& b)
    {
        return a.mssv < b.mssv;
    });
    Node* newHead = nullptr;
    Node* tail = nullptr;
    for (const SV& sv : svVector)
    {
        Node* newNode = new Node{sv, nullptr};
        if (newHead == nullptr)
            newHead = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = newHead;
}
bool sosanh_dtb(const SV& sv1, const SV& sv2)
{
    return sv1.dtb < sv2.dtb;
}
void nhap_ttsv(SV &ds)
{
    cout << "Nhap MSSV: "; cin >> ds.mssv;
    cin.ignore(32767, '\n');
    cout << "Nhap ho ten: "; getline(cin, ds.name);
    cout << "Nhap gioi tinh: "; getline(cin, ds.sx);
    cout << "Nhap dia chi: "; getline(cin, ds.dis);
    cout << "Nhap diem trung binh: "; cin >> ds.dtb;
}

void xuat_ttsv(SV &ds)
{
    cout << left << setw(10) << ds.mssv << setw(20) << ds.name << setw(15) << ds.sx << setw(15) << ds.dis << setw(15) << ds.dtb << endl;
}
int tim_ttsv(string ms)
{
    Node* current = head;
    int index = 0;
    while (current != nullptr)
    {
        if (current->data.mssv == ms)
            return index;
        current = current->next;
        index++;
    }
    return -1;
}
void sua_ttsv(string ms)
{
    Node* current = head;
    while(current != nullptr)
    {
        if(current->data.mssv == ms)
        {
            string names, sxs, diss; float dtbs;
            cin.ignore(32767, '\n');
            cout << "Nhap ho ten: "; getline(cin, names); current->data.name = names;
            cout << "Nhap gioi tinh: "; getline(cin, sxs); current->data.sx = sxs;
            cout << "Nhap dia chi: "; getline(cin, diss); current->data.dis = diss;
            cout << "Nhap diem trung binh: "; cin >> dtbs; current->data.dtb = dtbs;
            return;
        }
        current = current->next;
    }
    cout << "Khong tim thay sinh vien" << endl;
}
void xoa_ttsv(string ms)
{
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr)
    {
        if (current->data.mssv == ms)
        {
            if (prev != nullptr)
                prev->next = current->next;
            else
                head = current->next;
            delete current;
            cout << "Da xoa sinh vien" << endl;
            n--;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Khong tim thay sinh vien" << endl;
}
void chuc_nang(SV ds[])
{
    cout << "*****************************************************************" << endl;
    cout << "**********        CHUONG TRINH QUAN LY SINH VIEN       **********" << endl;
    cout << "*****************************************************************" << endl;
    cout << "***   1. In ra danh sach sinh vien                            ***" << endl;
    cout << "***   2. Nhap them sinh vien                                  ***" << endl;
    cout << "***   3. Sua thong tin 1 sinh vien voi MSSV                   ***" << endl;
    cout << "***   4. Tim kiem thong tin sinh vien voi MSSV                ***" << endl;
    cout << "***   5. Xoa 1 sinh vien voi MSSV                             ***" << endl;
    cout << "***   6. Sap xep danh sach SV theo thu tu tang dan cua DTB    ***" << endl;
    cout << "***   7. Liet ke cac sinh vien co DTB >= x                    ***" << endl;
    cout << "***   8. So luong sinh vien theo gioi tinh                    ***" << endl;
    cout << "***   9. Thoat                                                ***" << endl;
    cout << "*****************************************************************" << endl;
    cout << "Chon chuc nang: "; int k; cin >> k;
    switch (k)
    {
        case 1: // in ds
        {
            if(n == 0)
                cout << "Danh sach rong !!!" << endl;
            else
            {
                cout << "(0: Theo MSSV | 1: Tat ca cac sinh vien): "; int k; cin >> k;
                cout << left << setw(10) << "MSSV" << setw(20) << "Ho va Ten" << setw(15) << "Gioi tinh" << setw(15) << "Dia chi" << setw(15) << "Diem Trung Binh" << endl;
                if(k == 0)
                {
                    cout << "Nhap mssv can in: "; string ms; cin >> ms;
                    int k = tim_ttsv(ms);
                    if(k == -1)
                        cout << "Khong tim thay sinh vien" << endl;
                    else
                        xuat_ttsv(head->data);
                }
                else
                {
                    Node* current = head;
                    while (current != nullptr)
                    {
                        xuat_ttsv(current->data);
                        current = current->next;
                    }
                }
            }
            break;
        }
        case 2: // nhap ds
        {
            cout << "Nhap so luong sinh vien: "; int x; cin >> x; 
            for(int i = n; i < n + x; i++)
            {

                cout << "---   Nhap thong tin sinh vien " << i + 1 << "   ---" << endl;
                SV ds;
                nhap_ttsv(ds);
                Node* newNode = new Node;
                newNode->data = ds;
                newNode->next = head;
                head = newNode;
            }
            n += x;
            sosanh_mssv(head);
            break;
        }
        case 3: // sua ds
        {
            cout << "Nhap mssv can sua: "; string ms; cin >> ms;
            sua_ttsv(ms); 
            break;
        }
        case 4: // search ds
        {
            cout << "Nhap mssv can tim kiem: "; string ms; cin >> ms;
            int k = tim_ttsv(ms);
            if(k == -1) cout <<"Khong tim thay sinh vien";
            else
            {
                cout << left << setw(10) << "MSSV" << setw(20) << "Ho va Ten" << setw(15) << "Gioi tinh" << setw(15) << "Dia chi" << setw(15) << "Diem Trung Binh" << endl;
                xuat_ttsv(head->data);
            }
            break;
        }
        case 5: // xoa ds
        {
            cout << "Nhap mssv can xoa: "; string ms; cin >> ms;
            xoa_ttsv(ms);
            break;
        }
        case 6: // dtb up
        {
            cout << "----- Danh sach sinh vien theo thu tu tang dan diem trung binh -----" << endl;
            cout << left << setw(10) << "MSSV" << setw(20) << "Ho va Ten" << setw(15) << "Gioi tinh" << setw(15) << "Dia chi" << setw(15) << "Diem Trung Binh" << endl;
            SV* ds_tam = new SV[n];
            Node* current = head;
            int index = 0;
            while (current != nullptr)
            {
                ds_tam[index++] = current->data;
                current = current->next;
            }
            sort(ds_tam, ds_tam + n, sosanh_dtb);
            for (int i = 0; i < n; i++)
                xuat_ttsv(ds_tam[i]);
            delete[] ds_tam;
            break;
        }
        case 7: // list dtb >= x
        {
            cout << "Nhap x: "; float x; cin >> x;
            cout << "----- Danh sach sinh vien co diem trung binh >= " << x << " -----" << endl;
            cout << left << setw(10) << "MSSV" << setw(20) << "Ho va Ten" << setw(15) << "Gioi tinh" << setw(15) << "Dia chi" << setw(15) << "Diem Trung Binh" << endl;
            Node* current = head;
            while (current != nullptr)
            {
                if (current->data.dtb >= x)
                    xuat_ttsv(current->data);
                current = current->next;
            }
            break;
        }
        case 8: // Cnt gender
        {
            int cnt_m = 0, cnt_f = 0;
            Node* current = head;
            while (current != nullptr)
            {
                string s = current->data.sx;
                if (s[1] == 'a')
                    cnt_m++;
                else
                    cnt_f++;
                current = current->next;
            }
            cout << "So luong sinh vien nam: " << cnt_m << endl;
            cout << "So luong sinh vien nu: " << cnt_f << endl;
            break;
        }
        default: //exit
            exit(1);
            break;
    }
}

void solve()
{
    SV ds[50];
    int k = 1;
    while (k != 0)
    {
        chuc_nang(ds);
        cout << "Ban co muon tiep tuc? (0: NO || 1: YES):  "; cin >> k;
    }
}
signed main()
{
    
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("inp.txt", "r", stdin); freopen("out.txt", "w", stdout);
    // #endif
    
    
    // int t; cin >> t;
    int t = 1;
    while (t--)
        solve();
}