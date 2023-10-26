#include <bits/stdc++.h>
#include <fstream>

using namespace std;
#define endl '\n'

using ll = long long;
using ull = unsigned long long;

const ll modd = 1e9 + 7;
const ll inf = 1e9;
const int N = 1e6 + 7;

const string filename = "student.txt";

struct SV
{
    string mssv, name, sx, dis;
    float dtb;
    int age;
};
int n;

void readFile(string filename, vector <SV> &ds)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Failed to open file " << filename << "." << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;

        SV ds1;
        getline(ss, token, ';');
        ds1.mssv = token;
        getline(ss, token, ';');
        ds1.name = token;
        getline(ss, token, ';');
        ds1.age = stoi(token);
        getline(ss, token, ';');
        ds1.sx = token;
        getline(ss, token, ';');
        ds1.dis = token;
        getline(ss, token, ';');
        ds1.dtb = stof(token);
        ds.push_back(ds1);
    }

    file.close();
}
void saveFile(string filename, vector <SV> &ds)
{
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file " << filename << "." << endl;
        return;
    }

    for (auto &i: ds) {
        file << i.mssv << ";" << i.name << ";" << i.age << ";" << i.sx << ";" << i.dis << ";" << fixed << setprecision(2) << i.dtb << "\n";
    }
    file.close();
}

void ss_mssv_ascending(vector <SV> &ds, int l, int r)
{
    if(l >= r) return;
    string x = ds[(l + r) / 2].mssv;
    int i = l, j = r;
    while(i < j)
    {
        while(ds[i].mssv < x) i++;
        while(ds[j].mssv > x) j--;
        if(i <= j)
        {
            swap(ds[i], ds[j]);
            i++; j--;
        }
    }
    if(l < j) ss_mssv_ascending(ds, l, j);
    if(i < r) ss_mssv_ascending(ds, i, r);
}
void ss_dtb_ascending(vector <SV> &ds, int l, int r)
{
    if(l >= r) return;
    float x = ds[(l + r) / 2].dtb;
    int i = l, j = r;
    while(i < j)
    {
        while(ds[i].dtb < x) i++;
        while(ds[j].dtb > x) j--;
        if(i <= j)
        {
            swap(ds[i], ds[j]);
            i++; j--;
        }
    }
    if(l < j) ss_dtb_ascending(ds, l, j);
    if(i < r) ss_dtb_ascending(ds, i, r);
}
bool check_name(const string &s)
{
    for(char k: s)
        if(!isalpha(k) && k != ' ') return false;
    return true;
}
int tim_ttsv(vector <SV> &ds, string ms)
{
    int l = 0, r = ds.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ds[mid].mssv == ms)
            return mid;
        else if (ds[mid].mssv < ms)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
void sua_ttsv(vector <SV> &ds, string ms)
{
    int k = tim_ttsv(ds, ms);
    if (k == -1)
        cout << "Khong tim thay sinh vien" << endl;
    else
    {
        string names, sxs, diss;
        float dtbs; int ages;
        cin.ignore(32767, '\n');
        cout << "Nhap ho ten: "; getline(cin, names);
        while(!check_name(names))
        {
            cout << "Nhap sai cu phap. Vui long nhap lai! " << endl;
            cout << "Nhap ho ten: "; getline(cin, names);
        }
        ds[k].name = names;
        cout << "Nhap tuoi: "; cin >> ages;
        ds[k].age = ages;
        cin.ignore(32767, '\n');
        cout << "Nhap gioi tinh: "; getline(cin, sxs);
        while(!(sxs == "Nam" || sxs == "nam" || sxs == "Nu" || sxs == "nu"))
        {
            cout << "Nhap sai cu phap. Vui long nhap lai! " << endl;
            cout << "Nhap gioi tinh: "; getline(cin, sxs);
        }
        ds[k].sx = sxs;
        cout << "Nhap dia chi: "; getline(cin, diss);
        ds[k].dis = diss;
        cout << "Nhap diem trung binh: "; cin >> dtbs;
        ds[k].dtb = dtbs;
    }
}
void xoa_ttsv(vector <SV> &ds, string ms)
{
    int k = tim_ttsv(ds, ms);
    if (k == -1)
        cout << "Khong tim thay sinh vien" << endl;
    else
    {
        ds.erase(ds.begin() + k);
        cout << "Da xoa sinh vien" << endl;
    }
}
void nhap_ttsv(vector <SV> &ds, int n)
{
    SV a;
    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap thong tin sinh vien thu " << i << ":" << endl;
        cin.ignore(32767, '\n');
        cout << "Nhap MSSV: ";  getline(cin, a.mssv);
        while(tim_ttsv(ds, a.mssv) != -1 || a.mssv.size() != 8)
        {
            cout << "MSSV da ton tai hoac nhap khong hop le" << endl;
            cout << "Nhap MSSV: "; getline(cin, a.mssv);
        }
        cout << "Nhap ho ten: "; getline(cin, a.name);
        while(!check_name(a.name))
        {
            cout << "Nhap sai cu phap. Vui long nhap lai! " << endl;
            cout << "Nhap ho ten: "; getline(cin, a.name);
        }
        cout << "Nhap tuoi: "; cin >> a.age;
        cin.ignore(32767, '\n');
        cout << "Nhap gioi tinh: "; getline(cin, a.sx);
        while(!(a.sx == "Nam" || a.sx == "nam" || a.sx == "Nu" || a.sx == "nu"))
        {
            cout << "Nhap sai cu phap. Vui long nhap lai! " << endl;
            cout << "Nhap gioi tinh: "; getline(cin, a.sx);
        }
        cout << "Nhap dia chi: "; getline(cin, a.dis);
        cout << "Nhap diem trung binh: "; cin >> a.dtb;
    }
    ds.push_back(a);
}
void xuat_ttsv(vector <SV> &ds, int fi, int se, int x)
{
    for(int i = 0; i < 87; i++)
    {
        if(i < 11) cout << " ";
        else
        {
            if(i == 11 || i == 20 || i == 48 || i == 53 || i == 63 || i == 80 || i == 86) cout << "+";
            else cout << "-";
        }
    }
    cout << endl;
    cout << setw(12) << "|" << "MSSV"  << setw(5) << "|"
         << "Ho va Ten" << setw(19) << "|"
         << "Tuoi" << "|"
         << "Gioi tinh" << "|"
         << "Thanh Pho" << setw(8) << "|"
         << "DTB" << setw(3)<< "|"<< endl;
    for(int i = 0; i < 87; i++)
    {
        if(i < 11) cout << " ";
        else
        {
            if(i == 11 || i == 20 || i == 48 || i == 53 || i == 63 || i == 80 || i == 86) cout << "+";
            else cout << "-";
        }
    }
    cout << endl;
    for(int i = fi; i <= se; i++)
        if(ds[i].dtb >= x)
            cout << setw(12) << "|" << ds[i].mssv << "|"
                 << ds[i].name << setw(28 - ds[i].name.size()) << "|"
                 << ds[i].age << setw(ds[i].age >= 10 ? 3 : 4) << "|"
                 << ds[i].sx << setw(10 - ds[i].sx.size()) << "|"
                 << ds[i].dis << setw(17 - ds[i].dis.size()) << "|"
                 << fixed << setprecision(2) << ds[i].dtb << setw(ds[i].dtb == 10 ? 1: 2)<< "|" << endl;
    for(int i = 0; i < 87; i++)
    {
        if(i < 11) cout << " ";
        else
        {
            if(i == 11 || i == 20 || i == 48 || i == 53 || i == 63 || i == 80 || i == 86) cout << "+";
            else cout << "-";
        }
    }
    cout << endl;
}
void menu()
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
}
void chuc_nang(vector <SV> &ds)
{
    cout << "Chon chuc nang: "; int k; cin >> k;
    switch (k)
    {
        case 1: // in ds
        {
            if (ds.size() == 0) cout << "Danh sach rong !!!" << endl;
            else
            {
                ss_mssv_ascending(ds, 0, ds.size() - 1);
                xuat_ttsv(ds, 0, ds.size() - 1, -1);
            }
            break;
        }
        case 2: // nhap ds
        {
            cout << "Nhap so luong sinh vien can them : "; int x; cin >> x;
            nhap_ttsv(ds, x);
            saveFile(filename, ds);
            break;
        }
        case 3: // sua ds
        {
            cout << "Nhap mssv can sua: "; string ms; cin >> ms;
            sua_ttsv(ds, ms);
            saveFile(filename, ds);
            break;
        }
        case 4: // search ds
        {
            cout << "Nhap mssv can tim kiem: "; string ms; cin >> ms;
            int k = tim_ttsv(ds, ms);
            if (k == -1)
                cout << "Khong tim thay sinh vien";
            else
                xuat_ttsv(ds, k, k, -1);
            break;
        }
        case 5: // xoa sv
        {
            cout << "Nhap mssv can xoa: "; string ms; cin >> ms;
            xoa_ttsv(ds, ms);
            saveFile(filename, ds);
            break;
        }
        case 6: // dtb up
        {
            cout << "----- Danh sach sinh vien theo thu tu tang dan diem trung binh -----" << endl;
            ss_dtb_ascending(ds, 0, ds.size() - 1);
            xuat_ttsv(ds, 0, ds.size() - 1, -1);
            saveFile(filename, ds);
            break;
        }
        case 7: // list dtb >= x
        {
            cout << "Nhap x: "; float x; cin >> x;
            cout << "----- Danh sach sinh vien co diem trung binh >= " << x << " -----" << endl;
            xuat_ttsv(ds, 0, ds.size() - 1, x);
            break;
        }
        case 8: // Cnt gender
        {
            int cnt_m = 0, cnt_f = 0;
            for (ll i = 0; i < ds.size(); i++)
                if (ds[i].sx == "nam" || ds[i].sx == "Nam")
                    cnt_m++;
                else
                    cnt_f++;
            cout << "So luong sinh vien nam: " << cnt_m << endl;
            cout << "So luong sinh vien nu: " << cnt_f << endl;
            break;
        }
        default: // exit
        {
            cout << "Thoat chuong trinh" << endl;
            exit(1);
        }
    }
}

void solve()
{
    vector<SV> ds;
    readFile(filename, ds);
    menu();
    while (true)
        chuc_nang(ds);
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
