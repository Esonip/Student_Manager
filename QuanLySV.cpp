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
int n;

bool sosanh_mssv(const SV& sv1, const SV& sv2)
{
    return sv1.mssv < sv2.mssv;
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
int tim_ttsv(SV ds[], string ms)
{
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(ds[mid].mssv == ms) return mid;
        else if(ds[mid].mssv < ms) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
void sua_ttsv(SV ds[], string ms)
{
    int k = tim_ttsv(ds, ms);
    if(k == -1)
        cout << "Khong tim thay sinh vien" << endl;
    else
    {
        string names, sxs, diss; float dtbs;
        cin.ignore(32767, '\n');
        cout << "Nhap ho ten: "; getline(cin, names); ds[k].name = names;
        cout << "Nhap gioi tinh: "; getline(cin, sxs); ds[k].sx = sxs;
        cout << "Nhap dia chi: "; getline(cin, diss); ds[k].dis = diss;
        cout << "Nhap diem trung binh: "; cin >> dtbs; ds[k].dtb = dtbs;
    }
}
void xoa_ttsv(SV ds[], string ms)
{
    int k = tim_ttsv(ds, ms);
    if(k == -1)
        cout << "Khong tim thay sinh vien" << endl;
    else
    {
        for(int i = k; i < n; i++)
            ds[i] = ds[i + 1];
        n--;
        cout << "Da xoa sinh vien" << endl;
    }
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
                    int k = tim_ttsv(ds, ms);
                    if(k == -1)
                        cout << "Khong tim thay sinh vien" << endl;
                    else xuat_ttsv(ds[k]);
                }
                else
                    for (int i = 0; i < n; i++)
                        xuat_ttsv(ds[i]);
            }
            break;
        }
        case 2: // nhap ds
        {
            cout << "Nhap so luong sinh vien: "; int x; cin >> x; 
            for(int i = n; i < n + x; i++)
            {

                cout << "---   Nhap thong tin sinh vien " << i + 1 << "   ---" << endl;
                nhap_ttsv(ds[i]);
            }
            n += x;
            sort(ds, ds + n, sosanh_mssv);
            break;
        }
        case 3: // sua ds
        {
            cout << "Nhap mssv can sua: "; string ms; cin >> ms;
            sua_ttsv(ds, ms); 
            break;
        }
        case 4: // search ds
        {
            cout << "Nhap mssv can tim kiem: "; string ms; cin >> ms;
            int k = tim_ttsv(ds, ms);
            if(k == -1) cout <<"Khong tim thay sinh vien";
            else
            {
                cout << left << setw(10) << "MSSV" << setw(20) << "Ho va Ten" << setw(15) << "Gioi tinh" << setw(15) << "Dia chi" << setw(15) << "Diem Trung Binh" << endl;
                xuat_ttsv(ds[k]);
            }
            break;
        }
        case 5: // xoa ds
        {
            cout << "Nhap mssv can xoa: "; string ms; cin >> ms;
            xoa_ttsv(ds, ms);
            break;
        }
        case 6: // dtb up
        {
            cout << "----- Danh sach sinh vien theo thu tu tang dan diem trung binh -----" << endl;
            cout << left << setw(10) << "MSSV" << setw(20) << "Ho va Ten" << setw(15) << "Gioi tinh" << setw(15) << "Dia chi" << setw(15) << "Diem Trung Binh" << endl;
            sort(ds, ds + n, sosanh_dtb);
            for (int i = 0; i < n; i++)
                xuat_ttsv(ds[i]);
            sort(ds, ds + n, sosanh_mssv);
            break;
        }
        case 7: // list dtb >= x
        {
            cout << "Nhap x: "; float x; cin >> x;
            cout << "----- Danh sach sinh vien co diem trung binh >= " << x << " -----" << endl;
            cout << left << setw(10) << "MSSV" << setw(20) << "Ho va Ten" << setw(15) << "Gioi tinh" << setw(15) << "Dia chi" << setw(15) << "Diem Trung Binh" << endl;
            for(int i = 0; i < n; i++)
                if(ds[i].dtb >= x) xuat_ttsv(ds[i]);
            break;
        }
        case 8: // Cnt gender
        {
            int cnt_m = 0, cnt_f = 0;
            for(int i = 0; i < n; i++)
            {
                string s = ds[i].sx;
                if(s[1] == 'a') cnt_m++;
                else cnt_f++;
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
