/**
 * ԭ�����ӣ�https://leetcode.com/problems/n-queens-ii/ 
 * n�ʺ����⣬����˵���ǣ���һ��n * n�������ϣ�������� n ��λ�õĻʺ�
 * ʹ�����������ʺ���ͬһ�С�����ͬһ�С�����ͬһ�Խ��ߣ����������Խ��ߣ��ϣ�
 * ���������������н�������
 * ���ǻ��ݷ��ľ������⣬������Ҫ���ľ���������е������Ȼ����ݲ�ͬ�����������ݡ�
 */
 
/**
 * ���ȣ�����ж������ʺ��λ���ǲ�������Ҫ��ģ�
 * ���������һά����a[ i ]���洢�ʺ��λ�ã�
 * ���������±� i �������ڵ� i �У�Ԫ�ص�ֵ������a[ i ]�У�
 * �����±�Ψһ�����Բ���ͬһ���ǿ϶�����ģ�����ͬһ��ͨ�����ԱȽ�a[ i ]��a[ j ]����ֵ���жϣ�
 * ʣ�����ľ�������ж��ǲ�����ͬһ���Խ����ˣ�
 * �����ͬһ���Խ����ϣ����������������һ�������εĶԽǶ��㣬
 * ���������ε��ı߳���ȣ���������ֻҪ�ж��������ʺ�λ�õ�����֮�����ֵ�ǲ�����ȾͿ����ˣ�
 * ��a[ i ] - a[ j ] == i - j || a[ j ] - a[ i ] == i - j��
 * �����ڼ���ǰ��i - 1��λ�ö��Ѿ�����Ҫ�������£�
 * ֻҪ��ǰ��ÿһ�ж��� i �����Ƚ�һ�£��Ϳ��Եó���ǰλ���ǲ��ǳ�ͻ��.
 * �ⲿ�ִ������£�
 */
bool isConflict(int* a, int n) {
    bool flag = false;
    for(int i = 0; i < n; ++i) {
        if(a[n] == a[i] || (a[n] - a[i]) == (n - i) || (a[i] - a[n]) == (n - i)) {
            flag = true;
            break;
        }
    }
    return flag;
}

/**
 * ����������������Ĺ��̣���������Ĺ�ģ��n���±��Ǵ�0��n - 1���� 
 * ��������˼����:
 * �ڵ�ǰ i - 1 ���Ѿ�����ͻ������¿�ʼѰ����һ�У��� i �У��ʺ�ĺ���λ�ã�
 * �ӵ�0�е���n - 1�п�ʼѰ�ң�����ڵ� j �в���ͻ����ô�ͽ��е� i + 1�лʺ�ĳ��ԣ�
 * �������ĳһ�е�ʱ��һֱɨ�赽��n - 1�ж�û�к��ʵ�λ�õ�ʱ�����ʱ�����Ҫ���ݣ�
 * ����ǰɨ���е�������λ��0��Ȼ����ݵ���һ�У�����һ�еĻʺ�λ���������ƶ�һ�У�����������1����
 * Ȼ�����´���һ�п�ʼ�жϣ����������ϵ��жϲ��ϵĻ��ݣ�
 * ����n - 1�еĲ���ͻλ���Ѿ��ҵ���ʱ��
 * ���Ѿ��ҵ�һ�ַ���Ҫ��Ľⷨ�ˣ�Ȼ�������ټ�һ�����жϣ�
 * �Դ������������ݵ���0�У����������Ѿ��������ң���a[ 0 ] == n - 1��ʱ��
 * ��ʱ�Ѿ�û�а취�������ƶ��ˣ����������̽����� 
 */
 
 class Solution {
public:
    // �ж��Ƿ���ǰ n - 1 �г�ͻ
    bool isConflict(int* a, int n) {
        bool flag = false;
        for(int i = 0; i < n; ++i) {
            if(a[n] == a[i] || (a[n] - a[i]) == (n - i) || (a[i] - a[n]) == (n - i)) {
                flag = true;
                break;
            }
        }
        return flag;
    }
    int totalNQueens(int n) {
        int count = 0;
        int a[n] = {0}; // ��ʼ��Ϊ0
        int row = 0;
        while(1) {
            if(row == 0 && a[row] >= n) break; // �Ѿ��޷��ٻ���
            else if(row >= n) { // �ҵ�һ������Ҫ��Ľ�
                count++;
                row--;
                a[row]++;
                continue;
            }else if(a[row] >= n) { // ��ǰ���Ѿ���ٽ��������ݵ���һ��
                a[row] = 0;
                row--;
                a[row]++;
                continue;
            }
            if(isConflict(a,row)) { // ��ͻ���������һ��
                a[row]++;
            } else { // ����ͻ����ʼ��һ�е����
                row++;
            }
        }
        return count;
    }
};