#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//proccessing file  
void import_file();
void export_file();
void reimport();


//run method
void distribute_file_run(int m);
void run_merging();
void merge_file_run(int m);


//nature method
void distribute_file_nature(int arr[], int z);
void merge_file_nature();
void nature_merging();


//balanced method
void distribute_file_balanced(int arr_f0[], int length_f0);
void merge_file_balanced_f(int run_balanced_f[], int length_run_balanced_f, int length_f0);
void merge_file_balanced_g(int run_balanced_g[], int length_run_balanced_g, int length_f0);
void balanced_multiway_merging();

//merge sort algorithm
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

//declare variable
int m, n, N, arr[100], length_run_nature, run_nature[100], count_merge = 0;
fstream f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, g1, g2, g3, g4, g5, g6, g7, g8, g9, g10;

//test code 
//9 2 0 12 4 1 6 3 7  1 - 2  5 8 7 8 9
//m = 16
int main()
{
    import_file();
    cout << "----------------------------" << endl << "File ban dau: ";
    if (n == 0)
        cout << "\n----------------------------// Chuong trinh ket thuc! //----------------------------";
    else {
        export_file();
        cout << endl << "File co " << n << " phan tu!";
        cout << endl << "----------------------------";
        while (1) {
            int method;
            cout << endl<<setw(180)<<right<<"CAC PHUONG PHAP THUC HIEN";
            cout << endl<<setw(175)<<left <<"1.Phuong phap tron RUN";
            cout << endl<<setw(175)<< left <<"2.Phuong phap tron tu nhien";
            cout << endl<<setw(175)<< left <<"3.Phuong phap tron da loi can bang";
            cout << endl<<setw(190)<< left <<"0.Ket thuc chuong trinh";
            cout << "\n-------> Moi chon phuong phap thuc hien: ";
            cin >> method;
            if (method == 0) {
                cout << "\n----------------------------// Chuong trinh ket thuc! //----------------------------";
                break;
            }
            switch (method) {
                cin >> method;
            case 1: {
                cout << "\n----------//  Duoi day la qua trinh thuc hien phuong phap tron Run  //----------\n";
                reimport();
                run_merging();
                break;
            }
            case 2: {
                cout << "\n----------//  Duoi day la qua trinh thuc hien phuong phap tron tu nhien  //----------\n";
                reimport();
                nature_merging();
                break;
            }
            case 3: {
                cout << "\n----------//  Duoi day la qua trinh thuc hien phuong phap tron da loi can bang  //----------\n";
                count_merge = 0;
                reimport();
                balanced_multiway_merging();
                break;
            }
            default:
                break;
            }
        }
    }
}
void run_merging() {
    m = 1;
    int i = m;
    int count = 0;
    while (i < n) {
        count++;
        i = i * 2;
    }
    cout << "f0: File input, output\nf1: File tam thu nhat\nf2: File tam thu hai";
    cout << endl << "n: So luong phan tu co trong f0\nm: So phan tu duoc chia vao moi file tam sau moi lan chia!" << endl << "Qua trinh chia va tron file ke tiep se co gia tri m gap doi qua trinh lien truoc!" << endl << "Viec chia va tron file ket thuc khi m >= n!" << endl << "----------------------------";
    cout << endl << "File f0 co " << n << " phan tu thi co tat ca " << count << " lan tron." << endl << "----------------------------";
    count = 0;
    while (m < n) {
        cout << endl << "Ket qua 2 file tam sau khi chia lan thu " << count + 1 << " voi gia tri m = " << m << ".";
        distribute_file_run(m);
        merge_file_run(m);
        cout << endl << "File f0 sau khi tron file f1 va f2 lan thu " << count + 1 << " : ";
        export_file();
        count++;
        cout << endl << "----------------------------";
        m = m * 2;
        int maximum = max(m, n);
        if (maximum == m) cout << endl << "Voi m = " << m << " > n => Ket thuc viec chia file, dua ra output va ket thuc chuong trinh!";
    }
    cout << endl << "----------------------------" << endl;
    cout << "Ket qua cuoi cung sau khi qua trinh chia va tron file ket thuc:\nf0: ";
    export_file();
    cout << "\n----------//  Phuong phap tron Run ket thuc  //----------\n";
}
void nature_merging() {
    cout << "f0: File input, output\nf1: File tam thu nhat\nf2: File tam thu hai";
    cout << endl << "n: So luong phan tu co trong f0\nTan dung duoc tat ca cac RUN dai nhat co trong f0 trong khi chia du lieu\nViec chia va tron ket thuc khi trong f0 chi con duy nhat 1 RUN\n----------------------------";
    int distribute_numb = 0;
    while (n) {
        f0.open("C:\\Users\\thanh\\Documents\\test\\f0.txt", ios::in);
        char a[100];
        int arr[100], i = 0;
        while (f0 >> a) {
            arr[i] = atoi(a);
            i++;
        }
        f0.close();
        int count = 1, j = 0;
        for (j; j < i - 1; j++) {
            if (arr[j] > arr[j + 1])
                count++;
        }
        if (count > 1) {
            cout << "\nSo luong RUN hien co trong f0: " << count << " RUN => Thuc hien viec chia file!";
        }
        else {
            cout << "\nSo luong RUN hien co trong f0: " << 1 << " RUN => Ket thuc viec chia file, dua ra output va ket thuc chuong trinh!\n----------------------------";
            break;
        }
        cout << "\nKet qua 2 file tam sau khi chia lan thu " << distribute_numb + 1;
        distribute_file_nature(arr, i);
        merge_file_nature();
        cout << endl << "File f0 sau khi tron file f1 va f2 lan thu " << distribute_numb + 1 << " : ";
        export_file();
        cout << "\n----------------------------";
        distribute_numb++;
    }
    cout << endl << "Ket qua cuoi cung sau khi qua trinh chia va tron ket thuc:\nf0: ";
    export_file();
    cout << "\n----------//  Phuong phap tron tu nhien ket thuc  //----------\n";
}
void balanced_multiway_merging() {
    f0.open("C:\\Users\\thanh\\Documents\\test\\f0.txt", ios::in);
    char a[100];
    int arr_f0[100], length_f0 = 0;
    while (f0 >> a) {
        arr_f0[length_f0] = atoi(a);
        length_f0++;
    }
    f0.close();
    int count = 1;
    for (int i = 0; i < length_f0 - 1; i++) {
        if (arr_f0[i] > arr_f0[i + 1])
            count++;
    }
    cout << "f0: File input,output\nf_: File nguon\ng_: File dich\nSo luong file nguon va file dich bang nhau!\nSo luong file nguon phu thuoc vao so RUN co trong input\nThao tac tron ket thuc khi co 1 file nguon hoac file dich chi con 1 RUN dong thoi chieu dai dung bang chieu dai input!\n----------------------------";
    cout << "\nFile ban dau co " << count << " RUN nen co the chon toi da " << count << " file nguon!\n";
    if (count > 10) {
        while (1) {
            cout << "Nhap 0 < N <= 10: ";
            cin >> N;
            if (N > 0 && N <= 10)
                break;
        }
    }
    else {
        while (1) {
            cout << "Nhap 0 < N <= " << count << ": ";
            cin >> N;
            if (N > 0 && N <= count)
                break;
        }
    }
    /*if (N > 10) {
        cout << "Nhap N: ";
        cin >> N;
    }
    else if (N <= 0 || N > count) {
        cout << "Nhap N: ";
        cin >> N;
    }*/
    distribute_file_balanced(arr_f0, length_f0);
    cout << "\n----------------------------\nKet qua cuoi cung sau khi qua trinh tron ket thuc:\nf0: ";
    export_file();
    cout << "\n----------//  Phuong phap tron da loi can bang ket thuc  //----------\n";
}
void import_file() {
    int i, x;
    f0.open("C:\\Users\\thanh\\Documents\\test\\f0.txt", ios::out | ios::trunc);
    if (f0.is_open()) {
        cout << "Mo file thanh cong!\n" << "----------------------------" << endl;
        cout << "Chon so luong phan tu co trong file: ";
        cin >> n;
        cout << "Nhap cac phan tu co trong file:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            f0 << arr[i] << " ";
        }
        f0.close();
    }
    else
        cout << "Mo file khong thanh cong!";
}
void export_file() {
    int x;
    f0.open("C:\\Users\\thanh\\Documents\\test\\f0.txt", ios::in);
    int i = 0;
    char a[100];
    while (f0 >> a) {
        cout << a << " ";
    }
    f0.close();
}
void reimport() {
    f0.open("C:\\Users\\thanh\\Documents\\test\\f0.txt", ios::out | ios::trunc);
    for (int i = 0; i < n; i++)
        f0 << arr[i] << " ";
    f0.close();
}
void distribute_file_run(int m) {
    int count, x = 0;
    f0.open("C:\\Users\\thanh\\Documents\\test\\f0.txt", ios::in);
    f1.open("C:\\Users\\thanh\\Documents\\test\\f1.txt", ios::out | ios::trunc);
    f2.open("C:\\Users\\thanh\\Documents\\test\\f2.txt", ios::out | ios::trunc);
    char a[100];
    int arr[100], i = 0;
    while (f0 >> a) {
        arr[i] = atoi(a);
        i++;
    }
    cout << endl;
    for (int j = 0; j <= i; j++) {
        count = 0;
        for (x; x < i; x++) {
            f1 << arr[x] << " ";
            count++;
            if (count == m)
                break;
        }
        count = 0;
        x++;
        for (x; x < i; x++) {
            f2 << arr[x] << " ";
            count++;
            if (count == m)
                break;
        }
        x++;
        j = x;
    }
    f0.close();
    f1.close();
    f2.close();
    char b[100], c[100];
    f1.open("C:\\Users\\thanh\\Documents\\test\\f1.txt", ios::in);
    f2.open("C:\\Users\\thanh\\Documents\\test\\f2.txt", ios::in);
    cout << "f1: ";
    while (f1 >> b) {
        cout << b << " ";
    }
    cout << endl << "f2: ";
    while (f2 >> c) {
        cout << c << " ";
    }
    f1.close();
    f2.close();
}
void distribute_file_nature(int arr[], int z) {
    f1.open("C:\\Users\\thanh\\Documents\\test\\f1.txt", ios::out | ios::trunc);
    f2.open("C:\\Users\\thanh\\Documents\\test\\f2.txt", ios::out | ios::trunc);
    int i = 0;
    length_run_nature = 0;
    while (i < z) {
        int temp = 0;
        for (i; i < z; i++) {
            f1 << arr[i] << " ";
            temp++;
            if (arr[i] > arr[i + 1])
                break;
        }
        run_nature[length_run_nature] = temp;
        length_run_nature++;
        temp = 0;
        i++;
        for (i; i < z; i++) {
            f2 << arr[i] << " ";
            temp++;
            if (arr[i] > arr[i + 1])
                break;
        }
        if (temp != 0) {
            run_nature[length_run_nature] = temp;
            length_run_nature++;
        }
        i++;
    }
    f1.close();
    f2.close();
    char b[100], c[100];
    f1.open("C:\\Users\\thanh\\Documents\\test\\f1.txt", ios::in);
    f2.open("C:\\Users\\thanh\\Documents\\test\\f2.txt", ios::in);
    cout << "\nf1: ";
    while (f1 >> b) {
        cout << b << " ";
    }
    cout << endl << "f2: ";
    while (f2 >> c) {
        cout << c << " ";
    }
    f1.close();
    f2.close();
}
void distribute_file_balanced(int arr_f0[], int length_f0) {
    for (int i = 0; i < N; i++) {
        switch (i) {
        case 0: {
            f1.open("C:\\Users\\thanh\\Documents\\test\\f1.txt", ios::out | ios::trunc);
            break;
        }
        case 1: {
            f2.open("C:\\Users\\thanh\\Documents\\test\\f2.txt", ios::out | ios::trunc);
            break;
        }
        case 2: {
            f3.open("C:\\Users\\thanh\\Documents\\test\\f3.txt", ios::out | ios::trunc);
            break;
        }
        case 3: {
            f4.open("C:\\Users\\thanh\\Documents\\test\\f4.txt", ios::out | ios::trunc);
            break;
        }
        case 4: {
            f5.open("C:\\Users\\thanh\\Documents\\test\\f5.txt", ios::out | ios::trunc);
            break;
        }
        case 5: {
            f6.open("C:\\Users\\thanh\\Documents\\test\\f6.txt", ios::out | ios::trunc);
            break;
        }
        case 6: {
            f7.open("C:\\Users\\thanh\\Documents\\test\\f7.txt", ios::out | ios::trunc);
            break;
        }
        case 7: {
            f8.open("C:\\Users\\thanh\\Documents\\test\\f8.txt", ios::out | ios::trunc);
            break;
        }
        case 8: {
            f9.open("C:\\Users\\thanh\\Documents\\test\\f9.txt", ios::out | ios::trunc);
            break;
        }
        case 9: {
            f10.open("C:\\Users\\thanh\\Documents\\test\\f10.txt", ios::out | ios::trunc);
            break;
        }
        default:
            break;
        }
    }
    int i = 0, j = 0;
    int run_balanced_f[100], length_run_balanced_f = 0;
    while (i < length_f0) {
        for (int x = 0; x < N; x++) {
            int temp = 0;
            switch (x) {
            case 0: {
                for (i; i < length_f0; i++) {
                    f1 << arr_f0[i] << " ";
                    temp++;
                    if (arr_f0[i] > arr_f0[i + 1])
                        break;
                }
                if (temp != 0) {
                    run_balanced_f[length_run_balanced_f] = temp;
                    length_run_balanced_f++;
                }
                i++;
                break;
            }
            case 1: {
                for (i; i < length_f0; i++) {
                    f2 << arr_f0[i] << " ";
                    temp++;
                    if (arr_f0[i] > arr_f0[i + 1])
                        break;
                }
                if (temp != 0) {
                    run_balanced_f[length_run_balanced_f] = temp;
                    length_run_balanced_f++;
                }
                i++;
                break;
            }
            case 2: {
                for (i; i < length_f0; i++) {
                    f3 << arr_f0[i] << " ";
                    temp++;
                    if (arr_f0[i] > arr_f0[i + 1])
                        break;
                }
                if (temp != 0) {
                    run_balanced_f[length_run_balanced_f] = temp;
                    length_run_balanced_f++;
                }
                i++;
                break;
            }
            case 3: {
                for (i; i < length_f0; i++) {
                    f4 << arr_f0[i] << " ";
                    temp++;
                    if (arr_f0[i] > arr_f0[i + 1])
                        break;
                }
                if (temp != 0) {
                    run_balanced_f[length_run_balanced_f] = temp;
                    length_run_balanced_f++;
                }
                i++;
                break;
            }
            case 4: {
                for (i; i < length_f0; i++) {
                    f5 << arr_f0[i] << " ";
                    temp++;
                    if (arr_f0[i] > arr_f0[i + 1])
                        break;
                }
                if (temp != 0) {
                    run_balanced_f[length_run_balanced_f] = temp;
                    length_run_balanced_f++;
                }
                i++;
                break;
            }
            case 5: {
                for (i; i < length_f0; i++) {
                    f6 << arr_f0[i] << " ";
                    temp++;
                    if (arr_f0[i] > arr_f0[i + 1])
                        break;
                }
                if (temp != 0) {
                    run_balanced_f[length_run_balanced_f] = temp;
                    length_run_balanced_f++;
                }
                i++;
                break;
            }
            case 6: {
                for (i; i < length_f0; i++) {
                    f7 << arr_f0[i] << " ";
                    temp++;
                    if (arr_f0[i] > arr_f0[i + 1])
                        break;
                }
                if (temp != 0) {
                    run_balanced_f[length_run_balanced_f] = temp;
                    length_run_balanced_f++;
                }
                i++;
                break;
            }
            case 7: {
                for (i; i < length_f0; i++) {
                    f8 << arr_f0[i] << " ";
                    temp++;
                    if (arr_f0[i] > arr_f0[i + 1])
                        break;
                }
                if (temp != 0) {
                    run_balanced_f[length_run_balanced_f] = temp;
                    length_run_balanced_f++;
                }
                i++;
                break;
            }
            case 8: {
                for (i; i < length_f0; i++) {
                    f9 << arr_f0[i] << " ";
                    temp++;
                    if (arr_f0[i] >> arr_f0[i + 1])
                        break;
                }
                if (temp != 0) {
                    run_balanced_f[length_run_balanced_f] = temp;
                    length_run_balanced_f++;
                }
                i++;
                break;
            }
            case 9: {
                for (i; i < length_f0; i++) {
                    f10 << arr_f0[i] << " ";
                    temp++;
                    if (arr_f0[i] > arr_f0[i + 1])
                        break;
                }
                if (temp != 0) {
                    run_balanced_f[length_run_balanced_f] = temp;
                    length_run_balanced_f++;
                }
                i++;
                break;
            }
            default:
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        switch (i) {
        case 0: {
            f1.close();
            break;
        }
        case 1: {
            f2.close();
            break;
        }
        case 2: {
            f3.close();
            break;
        }
        case 3: {
            f4.close();
            g4.close();
            break;
        }
        case 4: {
            f5.close();
            break;
        }
        case 5: {
            f6.close();
            break;
        }
        case 6: {
            f7.close();
            break;
        }
        case 7: {
            f8.close();
            break;
        }
        case 8: {
            f9.close();
            break;
        }
        case 9: {
            f10.close();
            break;
        }
        default:
            break;
        }
    }
    merge_file_balanced_f(run_balanced_f, length_run_balanced_f, length_f0);
}
void merge_file_run(int m) {
    int count;
    int stop, x = 0, y = 0;
    f0.open("C:\\Users\\thanh\\Documents\\test\\f0.txt", ios::out);
    f1.open("C:\\Users\\thanh\\Documents\\test\\f1.txt", ios::in);
    f2.open("C:\\Users\\thanh\\Documents\\test\\f2.txt", ios::in);
    char a[100], b[100];
    int c[100], arr_f1[100], arr_f2[100], i = 0, j = 0;
    while (f1 >> a) {
        arr_f1[i] = atoi(a);
        i++;
    }
    while (f2 >> b) {
        arr_f2[j] = atoi(b);
        j++;
    }
    f1.close();
    f2.close();
    int num_c = 0;
    for (int temp = 0; temp <= i; temp++) {
        count = 0;
        for (x; x < i; x++) {
            c[num_c] = arr_f1[x];
            num_c++;
            count++;
            if (count == m)
                break;
        }
        x++;
        count = 0;
        for (y; y < j; y++) {
            c[num_c] = arr_f2[y];
            num_c++;
            count++;
            if (count == m)
                break;
        }
        y++;
        temp = x;
        merge_sort(c, 0, num_c - 1);
        for (int h = 0; h < num_c; h++)
            f0 << c[h] << " ";
        num_c = 0;
    }
    f0.close();
}
void merge_file_nature() {
    f0.open("C:\\Users\\thanh\\Documents\\test\\f0.txt", ios::out);
    f1.open("C:\\Users\\thanh\\Documents\\test\\f1.txt", ios::in);
    f2.open("C:\\Users\\thanh\\Documents\\test\\f2.txt", ios::in);
    char a[100], b[100];
    int c[100], arr_nature_f1[100], arr_nature_f2[100], length_nature_f1 = 0, length_nature_f2 = 0;
    while (f1 >> a) {
        arr_nature_f1[length_nature_f1] = atoi(a);
        length_nature_f1++;
    }
    while (f2 >> b) {
        arr_nature_f2[length_nature_f2] = atoi(b);
        length_nature_f2++;
    }
    f1.close();
    f2.close();
    int i = 0, j = 0, count, numb_c = 0;
    for (int length = 0; length < length_run_nature; length++) {
        count = 0;
        for (i; i < length_nature_f1; i++) {
            c[numb_c] = arr_nature_f1[i];
            numb_c++;
            count++;
            if (count == run_nature[length])
                break;
        }
        i++;
        length++;
        count = 0;
        for (j; j < length_nature_f2; j++) {
            c[numb_c] = arr_nature_f2[j];
            numb_c++;
            count++;
            if (count == run_nature[length])
                break;
        }
        j++;
        merge_sort(c, 0, numb_c - 1);
        for (int x = 0; x < numb_c; x++)
            f0 << c[x] << " ";
        numb_c = 0;
    }
    f0.close();
}
void merge_file_balanced_f(int run_balanced_f[], int length_run_balanced_f, int length_f0) {
    for (int i = 0; i < N; i++) {
        switch (i) {
        case 0: {
            f1.open("C:\\Users\\thanh\\Documents\\test\\f1.txt", ios::in);
            g1.open("C:\\Users\\thanh\\Documents\\test\\g1.txt", ios::out | ios::trunc);
            break;
        }
        case 1: {
            f2.open("C:\\Users\\thanh\\Documents\\test\\f2.txt", ios::in);
            g2.open("C:\\Users\\thanh\\Documents\\test\\g2.txt", ios::out | ios::trunc);
            break;
        }
        case 2: {
            f3.open("C:\\Users\\thanh\\Documents\\test\\f3.txt", ios::in);
            g3.open("C:\\Users\\thanh\\Documents\\test\\g3.txt", ios::out | ios::trunc);
            break;
        }
        case 3: {
            f4.open("C:\\Users\\thanh\\Documents\\test\\f4.txt", ios::in);
            g4.open("C:\\Users\\thanh\\Documents\\test\\g4.txt", ios::out | ios::trunc);
            break;
        }
        case 4: {
            f5.open("C:\\Users\\thanh\\Documents\\test\\f5.txt", ios::in);
            g5.open("C:\\Users\\thanh\\Documents\\test\\g5.txt", ios::out | ios::trunc);
            break;
        }
        case 5: {
            f6.open("C:\\Users\\thanh\\Documents\\test\\f6.txt", ios::in);
            g6.open("C:\\Users\\thanh\\Documents\\test\\g6.txt", ios::out | ios::trunc);
            break;
        }
        case 6: {
            f7.open("C:\\Users\\thanh\\Documents\\test\\f7.txt", ios::in);
            g7.open("C:\\Users\\thanh\\Documents\\test\\g7.txt", ios::out | ios::trunc);
            break;
        }
        case 7: {
            f8.open("C:\\Users\\thanh\\Documents\\test\\f8.txt", ios::in);
            g8.open("C:\\Users\\thanh\\Documents\\test\\g8.txt", ios::out | ios::trunc);
            break;
        }
        case 8: {
            f9.open("C:\\Users\\thanh\\Documents\\test\\f9.txt", ios::in);
            g9.open("C:\\Users\\thanh\\Documents\\test\\g9.txt", ios::out | ios::trunc);
            break;
        }
        case 9: {
            f10.open("C:\\Users\\thanh\\Documents\\test\\f10.txt", ios::in);
            g10.open("C:\\Users\\thanh\\Documents\\test\\g10.txt", ios::out | ios::trunc);
            break;
        }
        default:
            break;
        }
    }
    char a1[100], a2[100], a3[100], a4[100], a5[100], a6[100], a7[100], a8[100], a9[100], a10[100];
    int c[100], arr_balanced_f1[100], arr_balanced_f2[100], arr_balanced_f3[100], arr_balanced_f4[100], arr_balanced_f5[100], arr_balanced_f6[100], arr_balanced_f7[100], arr_balanced_f8[100], arr_balanced_f9[100], arr_balanced_f10[100];
    int length_balanced_f1 = 0, length_balanced_f2 = 0, length_balanced_f3 = 0, length_balanced_f4 = 0, length_balanced_f5 = 0, length_balanced_f6 = 0, length_balanced_f7 = 0, length_balanced_f8 = 0, length_balanced_f9 = 0, length_balanced_f10 = 0;
    if (count_merge == 0) {
        cout << "\n----------------------------\nKet qua cac file dich sau khi phan bo!";
        count_merge++;
    }
    else {
        cout << "\n----------------------------\nKet qua sau khi tron lan thu " << count_merge << "!";
        count_merge++;
    }
    for (int i = 0; i < N; i++) {
        switch (i) {
        case 0: {
            while (f1 >> a1) {
                arr_balanced_f1[length_balanced_f1] = atoi(a1);
                length_balanced_f1++;
            }
            f1.close();
            cout << "\nf1: ";
            if (length_balanced_f1 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_f1; f++)
                    cout << arr_balanced_f1[f] << " ";
            }
            break;
        }
        case 1: {
            while (f2 >> a2) {
                arr_balanced_f2[length_balanced_f2] = atoi(a2);
                length_balanced_f2++;
            }
            f2.close();
            cout << "\nf2: ";
            if (length_balanced_f2 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_f2; f++)
                    cout << arr_balanced_f2[f] << " ";
            }
            break;
        }
        case 2: {
            while (f3 >> a3) {
                arr_balanced_f3[length_balanced_f3] = atoi(a3);
                length_balanced_f3++;
            }
            f3.close();
            cout << "\nf3: ";
            if (length_balanced_f3 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_f3; f++)
                    cout << arr_balanced_f3[f] << " ";
            }
            break;
        }
        case 3: {
            while (f4 >> a4) {
                arr_balanced_f4[length_balanced_f4] = atoi(a4);
                length_balanced_f4++;
            }
            f4.close();
            cout << "\nf4: ";
            if (length_balanced_f4 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_f4; f++)
                    cout << arr_balanced_f4[f] << " ";
            }
            break;
        }
        case 4: {
            while (f5 >> a5) {
                arr_balanced_f5[length_balanced_f5] = atoi(a5);
                length_balanced_f5++;
            }
            f5.close();
            cout << "\nf5: ";
            if (length_balanced_f5 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_f5; f++)
                    cout << arr_balanced_f5[f] << " ";
            }
            break;
        }
        case 5: {
            while (f6 >> a6) {
                arr_balanced_f6[length_balanced_f6] = atoi(a6);
                length_balanced_f6++;
            }
            f6.close();
            cout << "\nf6: ";
            if (length_balanced_f6 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_f6; f++)
                    cout << arr_balanced_f6[f] << " ";
            }
            break;
        }
        case 6: {
            while (f7 >> a7) {
                arr_balanced_f7[length_balanced_f7] = atoi(a7);
                length_balanced_f7++;
            }
            f7.close();
            cout << "\nf7: ";
            if (length_balanced_f7 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_f7; f++)
                    cout << arr_balanced_f7[f] << " ";
            }
            break;
        }
        case 7: {
            while (f8 >> a8) {
                arr_balanced_f8[length_balanced_f8] = atoi(a8);
                length_balanced_f8++;
            }
            f8.close();
            cout << "\nf8: ";
            if (length_balanced_f8 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_f8; f++)
                    cout << arr_balanced_f8[f] << " ";
            }
            break;
        }
        case 8: {
            while (f9 >> a9) {
                arr_balanced_f9[length_balanced_f9] = atoi(a9);
                length_balanced_f9++;
            }
            f9.close();
            cout << "\nf9: ";
            if (length_balanced_f9 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_f9; f++)
                    cout << arr_balanced_f9[f] << " ";
            }
            break;
        }
        case 9: {
            while (f10 >> a10) {
                arr_balanced_f10[length_balanced_f10] = atoi(a10);
                length_balanced_f10++;
            }
            f10.close();
            cout << "\nf10: ";
            if (length_balanced_f10 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_f10; f++)
                    cout << arr_balanced_f10[f] << " ";
            }
            break;
        }
        default:
            break;
        }
    }
    int run_balanced[100], length_run_balanced = 0, temp = 0, count_temp = 0, count_g = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0, i10 = 0, count, numb_c = 0;
    int length = 0;
    while (length < length_run_balanced_f) {
        for (int x = 0; x < N; x++) {
            count = 0;
            switch (x) {
            case 0: {
                for (i1; i1 < length_balanced_f1; i1++) {
                    c[numb_c] = arr_balanced_f1[i1];
                    numb_c++;
                    count++;
                    if (count == run_balanced_f[length])
                        break;
                }
                i1++;
                length++;
                break;
            }
            case 1: {
                for (i2; i2 < length_balanced_f2; i2++) {
                    c[numb_c] = arr_balanced_f2[i2];
                    numb_c++;
                    count++;
                    if (count == run_balanced_f[length])
                        break;
                }
                i2++;
                length++;
                break;
            }
            case 2: {
                for (i3; i3 < length_balanced_f3; i3++) {
                    c[numb_c] = arr_balanced_f3[i3];
                    numb_c++;
                    count++;
                    if (count == run_balanced_f[length])
                        break;
                }
                i3++;
                length++;
                break;
            }
            case 3: {
                for (i4; i4 < length_balanced_f4; i4++) {
                    c[numb_c] = arr_balanced_f4[i4];
                    numb_c++;
                    count++;
                    if (count == run_balanced_f[length])
                        break;
                }
                i4++;
                length++;
                break;
            }
            case 4: {
                for (i5; i5 < length_balanced_f5; i5++) {
                    c[numb_c] = arr_balanced_f5[i5];
                    numb_c++;
                    count++;
                    if (count == run_balanced_f[length])
                        break;
                }
                i5++;
                length++;
                break;
            }
            case 5: {
                for (i6; i6 < length_balanced_f6; i6++) {
                    c[numb_c] = arr_balanced_f4[i6];
                    numb_c++;
                    count++;
                    if (count == run_balanced_f[length])
                        break;
                }
                i6++;
                length++;
                break;
            }
            case 6: {
                for (i7; i7 < length_balanced_f7; i7++) {
                    c[numb_c] = arr_balanced_f7[i7];
                    numb_c++;
                    count++;
                    if (count == run_balanced_f[length])
                        break;
                }
                i7++;
                length++;
                break;
            }
            case 7: {
                for (i8; i8 < length_balanced_f8; i8++) {
                    c[numb_c] = arr_balanced_f8[i8];
                    numb_c++;
                    count++;
                    if (count == run_balanced_f[length])
                        break;
                }
                i8++;
                length++;
                break;
            }
            case 8: {
                for (i9; i9 < length_balanced_f9; i9++) {
                    c[numb_c] = arr_balanced_f9[i9];
                    numb_c++;
                    count++;
                    if (count == run_balanced_f[length])
                        break;
                }
                i9++;
                length++;
                break;
            }
            case 9: {
                for (i10; i10 < length_balanced_f10; i10++) {
                    c[numb_c] = arr_balanced_f10[i10];
                    numb_c++;
                    count++;
                    if (count == run_balanced_f[length])
                        break;
                }
                i10++;
                length++;
                break;
            }
            default:
                break;
            }
        }
        merge_sort(c, 0, numb_c - 1);
        switch (count_g) {
        case 0: {
            for (int l = 0; l < numb_c; l++) {
                g1 << c[l] << " ";
                count_temp++;
                temp++;
            }
            run_balanced[length_run_balanced] = temp;
            length_run_balanced++;
            temp = 0;
            numb_c = 0;
            break;
        }
        case 1: {
            for (int l = 0; l < numb_c; l++) {
                g2 << c[l] << " ";
                temp++;
            }
            run_balanced[length_run_balanced] = temp;
            length_run_balanced++;
            temp = 0;
            numb_c = 0;
            break;
        }
        case 2: {
            for (int l = 0; l < numb_c; l++) {
                g3 << c[l] << " ";
                temp++;
            }
            run_balanced[length_run_balanced] = temp;
            length_run_balanced++;
            temp = 0;
            numb_c = 0;
            break;
        }
        case 3: {
            for (int l = 0; l < numb_c; l++) {
                g4 << c[l] << " ";
                temp++;
            }
            run_balanced[length_run_balanced] = temp;
            length_run_balanced++;
            temp = 0;
            numb_c = 0;
            break;
        }
        case 4: {
            for (int l = 0; l < numb_c; l++) {
                g5 << c[l] << " ";
                temp++;
            }
            run_balanced[length_run_balanced] = temp;
            length_run_balanced++;
            temp = 0;
            numb_c = 0;
            break;
        }
        case 5: {
            for (int l = 0; l < numb_c; l++) {
                g6 << c[l] << " ";
                temp++;
            }
            run_balanced[length_run_balanced] = temp;
            length_run_balanced++;
            temp = 0;
            numb_c = 0;
            break;
        }
        case 6: {
            for (int l = 0; l < numb_c; l++) {
                g7 << c[l] << " ";
                temp;
            }
            run_balanced[length_run_balanced] = temp;
            length_run_balanced++;
            temp = 0;
            numb_c = 0;
            break;
        }
        case 7: {
            for (int l = 0; l < numb_c; l++) {
                g8 << c[l] << " ";
                temp++;
            }
            run_balanced[length_run_balanced] = temp;
            length_run_balanced++;
            temp = 0;
            numb_c = 0;
            break;
        }
        case 8: {
            for (int l = 0; l < numb_c; l++) {
                g9 << c[l] << " ";
                temp++;
            }
            run_balanced[length_run_balanced] = temp;
            length_run_balanced++;
            temp = 0;
            numb_c = 0;
            break;
        }
        case 9: {
            for (int l = 0; l < numb_c; l++) {
                g10 << c[l] << " ";
                temp++;
            }
            run_balanced[length_run_balanced] = temp;
            length_run_balanced++;
            temp = 0;
            numb_c = 0;
            break;
        }
        default:
            break;
        }
        count_g++;
    }
    for (int i = 0; i < N; i++) {
        switch (i) {
        case 0: {
            f1.close();
            g1.close();
            break;
        }
        case 1: {
            f2.close();
            g2.close();
            break;
        }
        case 2: {
            f3.close();
            g3.close();
            break;
        }
        case 3: {
            f4.close();
            g4.close();
            break;
        }
        case 4: {
            f5.close();
            g5.close();
            break;
        }
        case 5: {
            f6.close();
            g6.close();
            break;
        }
        case 6: {
            f7.close();
            g7.close();
            break;
        }
        case 7: {
            f8.close();
            g8.close();
            break;
        }
        case 8: {
            f9.close();
            g9.close();
            break;
        }
        case 9: {
            f10.close();
            g10.close();
            break;
        }
        default:
            break;
        }
    }
    if (count_temp == length_f0) {
        cout << "\n----------------------------\nKet qua sau khi tron lan thu " << count_merge << "!";
        count_merge++;
        cout << "\ng1: ";
        f0.open("C:\\Users\\thanh\\Documents\\test\\f0.txt", ios::out | ios::trunc);
        g1.open("C:\\Users\\thanh\\Documents\\test\\g1.txt", ios::in);
        char a[100];
        int arr_f0[100];
        while (g1 >> a) {
            cout << a << " ";
            f0 << a << " ";
        }
        f0.close();
        g1.close();
        for (int i = 1; i < N; i++) {
            switch (i) {
            case 1: {
                cout << "\ng2: NULL";
                break;
            }
            case 2: {
                cout << "\ng3: NULL";
                break;
            }
            case 3: {
                cout << "\ng4: NULL";
                break;
            }
            case 4: {
                cout << "\ng5: NULL";
                break;
            }
            case 5: {
                cout << "\ng6: NULL";
                break;
            }
            case 6: {
                cout << "\ng7: NULL";
                break;
            }
            case 7: {
                cout << "\ng8: NULL";
                break;
            }
            case 8: {
                cout << "\ng9: NULL";
                break;
            }
            case 9: {
                cout << "\ng10: NULL";
                break;
            }
            default:
                break;
            }
        }
        cout << "\n----------------------------\ng1 chi con 1 run dong thoi chieu dai dung bang chieu dai input\n=> Ket thuc viec tron, dua ra ket qua va ket thuc chuong trinh!";
    }
    else
        merge_file_balanced_g(run_balanced, length_run_balanced, length_f0);
}
void merge_file_balanced_g(int run_balanced_g[], int length_run_balanced_g, int length_f0) {
    for (int i = 0; i < N; i++) {
        switch (i) {
        case 0: {
            g1.open("C:\\Users\\thanh\\Documents\\test\\g1.txt", ios::in);
            f1.open("C:\\Users\\thanh\\Documents\\test\\f1.txt", ios::out | ios::trunc);
            break;
        }
        case 1: {
            g2.open("C:\\Users\\thanh\\Documents\\test\\g2.txt", ios::in);
            f2.open("C:\\Users\\thanh\\Documents\\test\\f2.txt", ios::out | ios::trunc);
            break;
        }
        case 2: {
            g3.open("C:\\Users\\thanh\\Documents\\test\\g3.txt", ios::in);
            f3.open("C:\\Users\\thanh\\Documents\\test\\f3.txt", ios::out | ios::trunc);
            break;
        }
        case 3: {
            g4.open("C:\\Users\\thanh\\Documents\\test\\g4.txt", ios::in);
            f4.open("C:\\Users\\thanh\\Documents\\test\\f4.txt", ios::out | ios::trunc);
            break;
        }
        case 4: {
            g5.open("C:\\Users\\thanh\\Documents\\test\\g5.txt", ios::in);
            f5.open("C:\\Users\\thanh\\Documents\\test\\f5.txt", ios::out | ios::trunc);
            break;
        }
        case 5: {
            g6.open("C:\\Users\\thanh\\Documents\\test\\g6.txt", ios::in);
            f6.open("C:\\Users\\thanh\\Documents\\test\\f6.txt", ios::out | ios::trunc);
            break;
        }
        case 6: {
            g7.open("C:\\Users\\thanh\\Documents\\test\\g7.txt", ios::in);
            f7.open("C:\\Users\\thanh\\Documents\\test\\f7.txt", ios::out | ios::trunc);
            break;
        }
        case 7: {
            g8.open("C:\\Users\\thanh\\Documents\\test\\g8.txt", ios::in);
            f8.open("C:\\Users\\thanh\\Documents\\test\\f8.txt", ios::out | ios::trunc);
            break;
        }
        case 8: {
            g9.open("C:\\Users\\thanh\\Documents\\test\\g9.txt", ios::in);
            f9.open("C:\\Users\\thanh\\Documents\\test\\f9.txt", ios::out | ios::trunc);
            break;
        }
        case 9: {
            g10.open("C:\\Users\\thanh\\Documents\\test\\g10.txt", ios::in);
            f10.open("C:\\Users\\thanh\\Documents\\test\\f10.txt", ios::out | ios::trunc);
            break;
        }
        default:
            break;
        }
    }
    char a1[100], a2[100], a3[100], a4[100], a5[100], a6[100], a7[100], a8[100], a9[100], a10[100];
    int c[100], run_balanced[100], arr_balanced_g1[100], arr_balanced_g2[100], arr_balanced_g3[100], arr_balanced_g4[100], arr_balanced_g5[100], arr_balanced_g6[100], arr_balanced_g7[100], arr_balanced_g8[100], arr_balanced_g9[100], arr_balanced_g10[100];
    int length_run_balanced = 0, length_balanced_g1 = 0, length_balanced_g2 = 0, length_balanced_g3 = 0, length_balanced_g4 = 0, length_balanced_g5 = 0, length_balanced_g6 = 0, length_balanced_g7 = 0, length_balanced_g8 = 0, length_balanced_g9 = 0, length_balanced_g10 = 0;
    cout << "\n----------------------------\nKet qua sau khi tron lan thu " << count_merge << "!";
    count_merge++;
    for (int i = 0; i < N; i++) {
        switch (i) {
        case 0: {
            while (g1 >> a1) {
                arr_balanced_g1[length_balanced_g1] = atoi(a1);
                length_balanced_g1++;
            }
            g1.close();
            cout << "\ng1: ";
            if (length_balanced_g1 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_g1; f++)
                    cout << arr_balanced_g1[f] << " ";
            }
            break;
        }
        case 1: {
            while (g2 >> a2) {
                arr_balanced_g2[length_balanced_g2] = atoi(a2);
                length_balanced_g2++;
            }
            g2.close();
            cout << "\ng2: ";
            if (length_balanced_g2 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_g2; f++)
                    cout << arr_balanced_g2[f] << " ";
            }
            break;
        }
        case 2: {
            while (g3 >> a3) {
                arr_balanced_g3[length_balanced_g3] = atoi(a3);
                length_balanced_g3++;
            }
            g3.close();
            cout << "\ng3: ";
            if (length_balanced_g3 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_g3; f++)
                    cout << arr_balanced_g3[f] << " ";
            }
            break;
        }
        case 3: {
            while (g4 >> a4) {
                arr_balanced_g4[length_balanced_g4] = atoi(a4);
                length_balanced_g4++;
            }
            g4.close();
            cout << "\ng4: ";
            if (length_balanced_g4 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_g4; f++)
                    cout << arr_balanced_g4[f] << " ";
            }
            break;
        }
        case 4: {
            while (g5 >> a5) {
                arr_balanced_g5[length_balanced_g5] = atoi(a5);
                length_balanced_g5++;
            }
            g5.close();
            cout << "\ng5: ";
            if (length_balanced_g5 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_g5; f++)
                    cout << arr_balanced_g5[f] << " ";
            }
            break;
        }
        case 5: {
            while (g6 >> a6) {
                arr_balanced_g6[length_balanced_g6] = atoi(a6);
                length_balanced_g6++;
            }
            g6.close();
            cout << "\ng6: ";
            if (length_balanced_g6 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_g6; f++)
                    cout << arr_balanced_g6[f] << " ";
            }
            break;
        }
        case 6: {
            while (g7 >> a7) {
                arr_balanced_g7[length_balanced_g7] = atoi(a7);
                length_balanced_g7++;
            }
            g7.close();
            cout << "\ng7: ";
            if (length_balanced_g7 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_g7; f++)
                    cout << arr_balanced_g7[f] << " ";
            }
            break;
        }
        case 7: {
            while (g8 >> a8) {
                arr_balanced_g8[length_balanced_g8] = atoi(a8);
                length_balanced_g8++;
            }
            g8.close();
            cout << "\ng8: ";
            if (length_balanced_g8 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_g8; f++)
                    cout << arr_balanced_g8[f] << " ";
            }
            break;
        }
        case 8: {
            while (g9 >> a9) {
                arr_balanced_g9[length_balanced_g9] = atoi(a9);
                length_balanced_g9++;
            }
            g9.close();
            cout << "\ng9: ";
            if (length_balanced_g9 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_g9; f++)
                    cout << arr_balanced_g9[f] << " ";
            }
            break;
        }
        case 9: {
            while (g10 >> a10) {
                arr_balanced_g10[length_balanced_g10] = atoi(a10);
                length_balanced_g10++;
            }
            f10.close();
            cout << "\ng10: ";
            if (length_balanced_g10 == 0)
                cout << "NULL";
            else {
                for (int f = 0; f < length_balanced_g10; f++)
                    cout << arr_balanced_g10[f] << " ";
            }
            break;
        }
        default:
            break;
        }
    }
    int temp = 0, count_temp = 0, count_f = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0, i10 = 0, count, numb_c = 0;
    int length = 0;
    while (length < length_run_balanced_g) {
        for (int x = 0; x < N; x++) {
            count = 0;
            switch (x) {
            case 0: {
                for (i1; i1 < length_balanced_g1; i1++) {
                    c[numb_c] = arr_balanced_g1[i1];
                    numb_c++;
                    count++;
                    if (count == run_balanced_g[length])
                        break;
                }
                i1++;
                length++;
                break;
            }
            case 1: {
                for (i2; i2 < length_balanced_g2; i2++) {
                    c[numb_c] = arr_balanced_g2[i2];
                    numb_c++;
                    count++;
                    if (count == run_balanced_g[length])
                        break;
                }
                i2++;
                length++;
                break;
            }
            case 2: {
                for (i3; i3 < length_balanced_g3; i3++) {
                    c[numb_c] = arr_balanced_g3[i3];
                    numb_c++;
                    count++;
                    if (count == run_balanced_g[length])
                        break;
                }
                i3++;
                length++;
                break;
            }
            case 3: {
                for (i4; i4 < length_balanced_g4; i4++) {
                    c[numb_c] = arr_balanced_g4[i4];
                    numb_c++;
                    count++;
                    if (count == run_balanced_g[length])
                        break;
                }
                i4++;
                length++;
                break;
            }
            case 4: {
                for (i5; i5 < length_balanced_g5; i5++) {
                    c[numb_c] = arr_balanced_g5[i5];
                    numb_c++;
                    count++;
                    if (count == run_balanced_g[length])
                        break;
                }
                i5++;
                length++;
                break;
            }
            case 5: {
                for (i6; i6 < length_balanced_g6; i6++) {
                    c[numb_c] = arr_balanced_g4[i6];
                    numb_c++;
                    count++;
                    if (count == run_balanced_g[length])
                        break;
                }
                i6++;
                length++;
                break;
            }
            case 6: {
                for (i7; i7 < length_balanced_g7; i7++) {
                    c[numb_c] = arr_balanced_g7[i7];
                    numb_c++;
                    count++;
                    if (count == run_balanced_g[length])
                        break;
                }
                i7++;
                length++;
                break;
            }
            case 7: {
                for (i8; i8 < length_balanced_g8; i8++) {
                    c[numb_c] = arr_balanced_g8[i8];
                    numb_c++;
                    count++;
                    if (count == run_balanced_g[length])
                        break;
                }
                i8++;
                length++;
                break;
            }
            case 8: {
                for (i9; i9 < length_balanced_g9; i9++) {
                    c[numb_c] = arr_balanced_g9[i9];
                    numb_c++;
                    count++;
                    if (count == run_balanced_g[length])
                        break;
                }
                i9++;
                length++;
                break;
            }
            case 9: {
                for (i10; i10 < length_balanced_g10; i10++) {
                    c[numb_c] = arr_balanced_g10[i10];
                    numb_c++;
                    count++;
                    if (count == run_balanced_g[length])
                        break;
                }
                i10++;
                length++;
                break;
            }
            default:
                break;
            }
        }
        merge_sort(c, 0, numb_c - 1);
        switch (count_f) {
        case 0: {
            for (int l = 0; l < numb_c; l++) {
                f1 << c[l] << " ";
                count_temp++;
                temp++;
            }
            if (temp != 0) {
                run_balanced[length_run_balanced] = temp;
                length_run_balanced++;
                temp = 0;
            }
            numb_c = 0;
            break;
        }
        case 1: {
            for (int l = 0; l < numb_c; l++) {
                f2 << c[l] << " ";
                temp++;
            }
            if (temp != 0) {
                run_balanced[length_run_balanced] = temp;
                length_run_balanced++;
                temp = 0;
            }
            numb_c = 0;
            break;
        }
        case 2: {
            for (int l = 0; l < numb_c; l++) {
                f3 << c[l] << " ";
                temp++;
            }
            if (temp != 0) {
                run_balanced[length_run_balanced] = temp;
                length_run_balanced++;
                temp = 0;
            }
            numb_c = 0;
            break;
        }
        case 3: {
            for (int l = 0; l < numb_c; l++) {
                f4 << c[l] << " ";
                temp++;
            }
            if (temp != 0) {
                run_balanced[length_run_balanced] = temp;
                length_run_balanced++;
                temp = 0;
            }
            numb_c = 0;
            break;
        }
        case 4: {
            for (int l = 0; l < numb_c; l++) {
                f5 << c[l] << " ";
                temp++;
            }
            if (temp != 0) {
                run_balanced[length_run_balanced] = temp;
                length_run_balanced++;
                temp = 0;
            }
            numb_c = 0;
            break;
        }
        case 5: {
            for (int l = 0; l < numb_c; l++) {
                f6 << c[l] << " ";
                temp++;
            }
            if (temp != 0) {
                run_balanced[length_run_balanced] = temp;
                length_run_balanced++;
                temp = 0;
            }
            numb_c = 0;
            break;
        }
        case 6: {
            for (int l = 0; l < numb_c; l++) {
                f7 << c[l] << " ";
                temp++;
            }
            if (temp != 0) {
                run_balanced[length_run_balanced] = temp;
                length_run_balanced++;
                temp = 0;
            }
            numb_c = 0;
            break;
        }
        case 7: {
            for (int l = 0; l < numb_c; l++) {
                f8 << c[l] << " ";
                temp++;
            }
            if (temp != 0) {
                run_balanced[length_run_balanced] = temp;
                length_run_balanced++;
                temp = 0;
            }
            numb_c = 0;
            break;
        }
        case 8: {
            for (int l = 0; l < numb_c; l++) {
                f9 << c[l] << " ";
                temp++;
            }
            if (temp != 0) {
                run_balanced[length_run_balanced] = temp;
                length_run_balanced++;
                temp = 0;
            }
            numb_c = 0;
            break;
        }
        case 9: {
            for (int l = 0; l < numb_c; l++) {
                f10 << c[l] << " ";
                temp++;
            }
            if (temp != 0) {
                run_balanced[length_run_balanced] = temp;
                length_run_balanced++;
                temp = 0;
            }
            numb_c = 0;
            break;
        }
        default:
            break;
        }
        count_f++;
    }
    for (int i = 0; i < N; i++) {
        switch (i) {
        case 0: {
            f1.close();
            g1.close();
            break;
        }
        case 1: {
            f2.close();
            g2.close();
            break;
        }
        case 2: {
            f3.close();
            g3.close();
            break;
        }
        case 3: {
            f4.close();
            g4.close();
            break;
        }
        case 4: {
            f5.close();
            g5.close();
            break;
        }
        case 5: {
            f6.close();
            g6.close();
            break;
        }
        case 6: {
            f7.close();
            g7.close();
            break;
        }
        case 7: {
            f8.close();
            g8.close();
            break;
        }
        case 8: {
            f9.close();
            g9.close();
            break;
        }
        case 9: {
            f10.close();
            g10.close();
            break;
        }
        default:
            break;
        }
    }
    if (count_temp == length_f0) {
        cout << "\n----------------------------\nKet qua sau khi tron lan thu " << count_merge << "!";
        count_merge++;
        cout << "\nf1: ";
        f0.open("C:\\Users\\thanh\\Documents\\test\\f0.txt", ios::out | ios::trunc);
        f1.open("C:\\Users\\thanh\\Documents\\test\\f1.txt", ios::in);
        char a[100];
        int arr_f0[100];
        while (f1 >> a) {
            cout << a << " ";
            f0 << a << " ";
        }
        f0.close();
        f1.close();
        for (int i = 1; i < N; i++) {
            switch (i) {
            case 1: {
                cout << "\nf2: NULL";
                break;
            }
            case 2: {
                cout << "\nf3: NULL";
                break;
            }
            case 3: {
                cout << "\nf4: NULL";
                break;
            }
            case 4: {
                cout << "\nf5: NULL";
                break;
            }
            case 5: {
                cout << "\nf6: NULL";
                break;
            }
            case 6: {
                cout << "\nf7: NULL";
                break;
            }
            case 7: {
                cout << "\nf8: NULL";
                break;
            }
            case 8: {
                cout << "\nf9: NULL";
                break;
            }
            case 9: {
                cout << "\nf10: NULL";
                break;
            }
            default:
                break;
            }
        }
        cout << "\n----------------------------\nf1 chi con 1 run dong thoi chieu dai dung bang chieu dai input\n=> Ket thuc viec tron, dua ra ket qua va ket thuc chuong trinh!";

    }
    else {
        merge_file_balanced_f(run_balanced, length_run_balanced, length_f0);
    }
}
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[100], R[100];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}