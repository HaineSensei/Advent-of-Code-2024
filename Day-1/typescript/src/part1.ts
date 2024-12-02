import * as fs from 'fs';

const data: [number, number][] = fs.readFileSync('../data.txt', 'utf8')
    .trim()
    .split('\n')
    .map(line => {
        const nums = line.split('   ').filter(s => s.length > 0).map(Number);
        return [nums[0], nums[1]] as [number, number];
    });

console.log(data);