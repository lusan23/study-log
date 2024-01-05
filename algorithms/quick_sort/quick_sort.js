// original code in python from https://www.programiz.com/dsa/quick-sort
var arr = [5,4 ,3, 2, 1];

function partition(arrr, low, high) {
	let pivot = arrr[high];
	let i = low - 1;
	console.log(`store:\n pivot:${arrr[high]}\ni:${low -1}`);
	for (let j = low; j <= high -1; j++){
		console.log(`arrr[j]:${arrr[j]} <= pivot:${pivot} ?`);
		if (arrr[j] <= pivot) {
			console.log(`it is! so increment i:${i} and swap arr[i]:${arrr[i]} by arr[j]:${arrr[j]}.`);
			i++;
	    	let tmp = arrr[i];
            arrr[i] = arrr[j];
            arrr[j] = tmp;
			tmp = null;
		} else {
			console.log("is not! continue the loop!");
		}
	}
	console.log(`loop is done! now swap arr[high${high}]:${arrr[high]} by arr[i:${i} + 1]:${arrr[high]}`);
    let tmpData = arrr[i + 1];
    arrr[i + 1] = arrr[high];
    arrr[high] = tmpData;
	console.log(arrr);
    tmpData = null;
	
	console.log(`return i:${i} + 1`)
    return i + 1;
}

function quickSort(arrr, low, high) {
	console.log(`low:${low} < high:${high} ?`);
	if (low < high) {
		console.log("it is, follow the func.")
		//console.log(`high:${high}\n low:${low}`);
		let pi = partition(arrr, low, high);

		console.log("recusive call to left!");
		quickSort(arrr, low, pi - 1);
		console.log("recusive call to right!");
		quickSort(arrr, pi + 1, high);

	} else {
		console.log("it's not! base case reached!");
	}

}
console.log(arr);

quickSort(arr,0, arr.length - 1);

console.log(arr);
