import * as fs from 'fs';

const data: [number, number][] = fs.readFileSync('../data.txt', 'utf8')
    .trim()
    .split('\n')
    .map(line => {
        const nums = line.split('   ').filter(s => s.length > 0).map(Number);
        return [nums[0], nums[1]] as [number, number];
    });
const data_first: number[] = data.map(a => a[0]).sort();
const data_second: number[] = data.map(a => a[1]).sort();
let total: number = 0;
for (let i = 0; i< data_first.length; i++) {
    total += Math.abs(data_first[i] - data_second[i]);
}
console.log(total);