using namespace std;
#include <stdio.h>
#include <iostream>
int block[10],process[10],number_blocks,number_process;
void Worstfit (){
    int segment[10], filler, block_pro[10], block_no[10];
    for (int i = 0; i < number_process; i++){
        for (int x = 0; x < number_blocks; x++){
            if (block_pro[x] != 1){
                filler = block[x] - process[i];
                if(filler >= 0){
                    block_no[i] = x;
                    break;
                }
            }
        }
        segment[i] = filler;
        block_pro[block_no[i]]=1;
    }
    cout << "Worst Fit:" << endl;
    cout << "Process No" << " " << "Process Size" << " " << "Block No" << " " << "Block Size" << " " << "Fragment" << endl;
    for (int y = 0; y < number_process; y++){
        cout << y+1 << " " << process[y] << " "
             << block_no[y] + 1 << " " << block[block_no[y]] <<
             " " << segment[y] << endl;
    }
}
void Bestfit (){
    int segment[10], filler, block_pro[10],block_no[10], min = 999;
    for (int x = 0; x < number_process; x++){
        for (int y = 0; y < number_blocks; y++){
            if (block_pro[y] != 1){
                filler = block[y] - process[x];
                if (filler>=0){
                    if (min > filler){
                        block_no[x] = y;
                        min = filler;
                    }
                }
            }
        }
        segment[x] = min;
        block_pro[block_no[x]] = 1;
        min = 999;
    }
    cout << "Best fit:" << endl;
    cout << "Process No" << " " << "Process Size" << " " << "Block No" << " " << "Block Size" << " " << "Fragment" << endl;
    for (int y = 0; y < number_process ; y++){
        cout << y+1 << " " << process[y] << " "
             << block_no[y] + 1 << " " << block[block_no[y]] <<
             " " << segment[y] << endl;
    }
}
void Firstfit (){
    int highest = 0, block_pro[10], block_no[10], segment[10],filler;
    for (int i=0;i<number_process; i++){
        for (int j=0; j< number_blocks; j++){
            if (block_pro[j] != 1){
                filler = block[j] - process[i];
                if (filler >= 0 )
                    if (highest < filler){
                        block_no[i] = j;
                        highest = filler;
                    }
            }
        }
        segment[i] = highest;
        block_pro[block_no[i]] = 1;
        highest = 0;
    }
    cout << "First Fit:" << endl;
    cout << "Process No" << " " << "Process Size" << " " << "Block No" << " " << "Block Size" << " " << "Fragment" << endl;
    for (int y = 0; y < number_process; y++){
        cout << y+1 << " " << process[y] << " "<< block_no[y] + 1 << " " << block[block_no[y]] << " " << segment[y] << endl;
    }
}
int main(){
    cout << "Please enter the number of blocks: ";
    cin >> number_blocks;
    cout << "Please enter ht enumber of processes: ";
    cin >> number_process;
    cout<< "" << endl;
    cout << "Enter the size of the blocks:" << endl;
    for (int i=0;i<number_blocks;i++) {
        cout << "Block " << i+1 << ": ";
        cin >> block[i];
    }
    cout<< "" << endl;
    cout << "Enter the size of the processes:" << endl;
    for (int x=0;x<number_process;x++){
        cout << "File " << x+1 << ": ";
        cin >> process[x];
    }
    cout<< "" << endl;
    Worstfit();
    cout<< "" << endl;
    Bestfit();
    cout<< "" << endl;
    Firstfit();
}
