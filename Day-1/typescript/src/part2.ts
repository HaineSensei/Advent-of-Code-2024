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
let sim_score: number = 0;
for (const x of data_first) {
    sim_score += x*data_second.filter(y => y === x).length;
}
console.log(sim_score);