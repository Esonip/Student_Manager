#include <bits/stdc++.h>
#include <fstream>

using namespace std;
#define endl '\n'

using ll = long long;
using ull = unsigned long long;

const ll modd = 1e9 + 7;
const ll inf = 1e9;
const int N = 1e6 + 7;

ifstream input("inp.txt");
ofstream output;

struct SV
{
    string mssv, name, sx, dis;
    float dtb;
} ds[50];
int n;

bool sosanh_mssv(const SV& sv1, const SV& sv2)
{
    return sv1.mssv < sv2.mssv;
}
bool sosanh_dtb(const SV& sv1, const SV& sv2) 
{
    return sv1.dtb < sv2.dtb;
}
void nhap_ttsv(SV &ds, ifstream &input)
{
    input >> ds.mssv;
    output << "Nhap MSSV: " << ds.mssv << endl;
    input.ignore(32767, '\n');
    getline(input, ds.name);
    output << "Nhap ho ten: " << ds.name << endl;
    getline(input, ds.sx);
    output << "Nhap gioi tinh: " << ds.sx << endl;
    getline(input, ds.dis);
    output << "Nhap dia chi: " << ds.dis << endl;
    input >> ds.dtb;
    output << "Nhap diem trung binh: " << float(ds.dtb) << endl;
}

void xuat_ttsv(SV &ds)
{
    output << left << setw(10) << ds.mssv << setw(20) << ds.name << setw(15) << ds.sx << setw(15) << ds.dis << setw(15) << ds.dtb << endl;
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
void sua_ttsv(SV ds[], string ms, ifstream &input)
{
    int k = tim_ttsv(ds, ms);
    if(k == -1)
        output << "Khong tim thay sinh vien" << endl;
    else
    {
        string names, sxs, diss; float dtbs;
        input.ignore(32767, '\n');
        getline(input, names); output << "Nhap ho ten: " << names << endl; ds[k].name = names;
        getline(input, sxs); output << "Nhap gioi tinh: " << sxs << endl; ds[k].sx = sxs;
        getline(input, diss); output << "Nhap dia chi: " << diss << endl; ds[k].dis = diss;
        input >> dtbs; output << "Nhap diem trung binh: " << dtbs << endl; ds[k].dtb = dtbs;
    }
}
void xoa_ttsv(SV ds[], string ms)
{
    int k = tim_ttsv(ds, ms);
    if(k == -1)
        output << "Khong tim thay sinh vien" << endl;
    else
    {
        for(int i = k; i < n; i++)
            ds[i] = ds[i + 1];
        n--;
        output << "Da xoa sinh vien" << endl;
    }
}
void chuc_nang(SV ds[])
{
    output << "*****************************************************************" << endl;
    output << "**********        CHUONG TRINH QUAN LY SINH VIEN       **********" << endl;
    output << "*****************************************************************" << endl;
    output << "***   1. In ra danh sach sinh vien                            ***" << endl;
    output << "***   2. Nhap them sinh vien                                  ***" << endl;
    output << "***   3. Sua thong tin 1 sinh vien voi MSSV                   ***" << endl;
    output << "***   4. Tim kiem thong tin sinh vien voi MSSV                ***" << endl;
    output << "***   5. Xoa 1 sinh vien voi MSSV                             ***" << endl;
    output << "***   6. Sap xep danh sach SV theo thu tu tang dan cua DTB    ***" << endl;
    output << "***   7. Liet ke cac sinh vien co DTB >= x                    ***" << endl;
    output << "***   8. So luong sinh vien theo gioi tinh                    ***" << endl;
    output << "***   9. Thoat                                                ***" << endl;
    output << "*****************************************************************" << endl;
    int k; input >> k;
    output << "Chon chuc nang: " << k << endl;
    switch (k)
    {
        case 1: // in ds
        {
            if(n == 0)
                output << "Danh sach rong !!!" << endl;
            else
            {
                int k; input >> k;
                output << "(0: Theo MSSV | 1: Tat ca cac sinh vien)" << k << endl;
                output << left << setw(10) << "MSSV" << setw(20) << "Ho va Ten" << setw(15) << "Gioi tinh" << setw(15) << "Dia chi" << setw(15) << "Diem Trung Binh" << endl;
                if(k == 0)
                {
                    string ms; input >> ms;
                    output << "Nhap mssv can in: " << ms << endl;
                    int k = tim_ttsv(ds, ms);
                    if(k == -1)
                        output << "Khong tim thay sinh vien" << endl;
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
            int x; input >> x;
            output << "Nhap so luong sinh vien: " << x << endl; 
            for(int i = n; i < n + x; i++)
            {
                output << "---   Nhap thong tin sinh vien " << i + 1 << "   ---" << endl;
                nhap_ttsv(ds[i], input);
            }
            n += x;
            sort(ds, ds + n, sosanh_mssv);
            break;
        }
        case 3: // sua ds
        {
            string ms; input >> ms;
            output << "Nhap mssv can sua: " << ms << endl;
            sua_ttsv(ds, ms, input); 
            break;
        }
        case 4: // search ds
        {
            string ms; input >> ms;
            output << "Nhap mssv can tim kiem: " << ms << endl;
            int k = tim_ttsv(ds, ms);
            if(k == -1) output <<"Khong tim thay sinh vien";
            else xuat_ttsv(ds[k]);
            break;
        }
        case 5: // xoa ds
        {
            string ms; input >> ms;
            output << "Nhap mssv can xoa: " << ms << endl;
            xoa_ttsv(ds, ms);
            break;
        }
        case 6: // dtb up
        {
            output << "----- Danh sach sinh vien theo thu tu tang dan diem trung binh -----" << endl;
            output << left << setw(10) << "MSSV" << setw(20) << "Ho va Ten" << setw(15) << "Gioi tinh" << setw(15) << "Dia chi" << setw(15) << "Diem Trung Binh" << endl;
            sort(ds, ds + n, sosanh_dtb);
            for (int i = 0; i < n; i++)
                xuat_ttsv(ds[i]);
            sort(ds, ds + n, sosanh_mssv);
            break;
        }
        case 7: // list dtb >= x
        {
            float x; input >> x;
            output << "Nhap x: " << x << endl;
            output << "----- Danh sach sinh vien co diem trung binh >= " << x << " -----" << endl;
            output << left << setw(10) << "MSSV" << setw(20) << "Ho va Ten" << setw(15) << "Gioi tinh" << setw(15) << "Dia chi" << setw(15) << "Diem Trung Binh" << endl;
            for(int i = 0; i < n; i++)
                if(ds[i].dtb >= x) xuat_ttsv(ds[i]);
            break;
        }
        case 8: // Cnt gender
        {
            int cnt_m = 0, cnt_f = 0;
            for(int i = 0; i < n; i++)
                if(ds[i].sx == "nam") cnt_m++;
                else cnt_f++;
            output << "So luong sinh vien nam: " << cnt_m << endl;
            output << "So luong sinh vien nu: " << cnt_f << endl;
            break;
        }
        default: //exit
            exit(1);
            break;
    }
}

void solve()
{
    output.open("out.txt");
    int k = 1;
    while (k != 0)
    {
        chuc_nang(ds); input >> k;
        output << "Ban co muon tiep tuc? (0: NO || 1: YES):  " << k << endl;
    }
    output.close();
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